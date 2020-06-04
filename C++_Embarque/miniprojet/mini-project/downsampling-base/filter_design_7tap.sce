// header-start
////////////////////////////////////////////////////////////////////////////////
// \project   yuv-viewer
//
// \file      filter_design_7tap.sce
//
// \brief     scilab script of a 7 TAP FIR filter for decimation by 2 
//
// \legal     Copyright (c) 2020
//
// \author    Bernard
//
////////////////////////////////////////////////////////////////////////////////
// header-end

Fc = 0.249;        // Normalized Cutoff Frequency
N = 7;           // Number of tap points in filter
Lobe = 19;        // Lanczos lobe function
Wc = 2*%pi*Fc;    // Omega in radian

function y=my_filter(x)
  Cx = (Wc/%pi)*sinc(Wc*x); // Coeff based on sinc(x) = sin(x)/x
  Wx = sinc((%pi/Lobe)*x);  // Lanczos Window   
  y  = Cx .* Wx;
endfunction


// For odd value of N
// We build a N vector of int centered at 0 : [-3 -2 -1 0 1 2 3]
// For even value of
// We build a N vector of int [-2.5 -1.5 -0.5 0.5 1.5 2.5]
if modulo(N,2) == 1 then
  n = [-(N-1)/2:1:(N-1)/2];
else 
  n = [-((N/2)-0.5):1:((N/2)-0.5)];
end


// Calculate the filter coefficients
// real number, no rounded

Ck = my_filter(n)
SCk = sum(Ck)

mprintf("Info: Normalized Coeff (sum = %f)\n",sum(Ck/SCk));
mprintf("% 3d % 7.4f\n",[n;Ck/SCk]');

// Additional padding for a "better" display n -> npad
npad = [n(1)-1,n,1-n(1)];

// Plot the Coeff value
// 1. As a continuous function
// 2. As dotted point on the integer values
clf();
subplot(1,2,1);

x = linspace(npad(1),-npad(1),512);
plot(x,my_filter(x)/SCk);
plot(n,Ck/SCk,'o');

//plot(Nref,Cref,">",'markerdg','green','markersize',10);
//plot(n,Ck,"o",'markerdg','blue','markersize',5);

// Addditional stuff to make things nice
set(gca(),'grid',[1 1]*color('gray'));
xlabel("n");
ylabel("C[n]");
title("Coeff Plot");

// Second Plot is the frequency response

subplot(1,2,2);
//X = linspace(0,1,1024);
//dfr=exp(2*%i*%pi*X);
//Hcalc=abs(freq(poly(Ck/SCk,"z","c"),1,dfr));
[Hcalc,fr] = frmag(Ck/SCk,512);
plot(fr,20*log10(Hcalc));
set(gca(),'grid',[1 1]*color('gray'));

// plot 3dB corner
plot([0 Fc]',20*log10([1/sqrt(2) 1/sqrt(2)]'),'red');
plot([Fc Fc]',20*log10([1/sqrt(2) 1E-3]'),'red');


xlabel("Normalized Freq");
ylabel("Magniture (dB)");
title("Magnitude Plot");





//
// find the rounded integer coefficient 
// such that the sum is feps.

feps = 2^15;
CkI = round(feps*Ck);

mprintf("INFO: EPS resolution = 1/%d = %f\n",feps,1/feps);
mprintf("INFO: Sum of the scaled coeff = %d\n",sum(CkI));


// Find the best scaling factor: scale_b
// We want sum( round(scale_b*Ck)) = feps
// So a first approximation is to have
// scale_a = feps/sum(Ck)

scale_a = feps/sum(Ck);
delta_a = sum(round(scale_a*Ck)) - feps;


//
// Step1: adjust the scale
// by a search within -1% to 1% around this first
// approximation
//
max_percent = round(abs(100*delta_a/feps))+1;
mprintf("Initial Delta = %d  (factor is : %.2f), withing %d%%\n",delta_a, scale_a,max_percent);

scale_b = scale_a
delta_b = delta_a

for i = -100*max_percent:100*max_percent

 
  scale_i = scale_a*(1 + i/10000);
  delta_i = sum(round(scale_i*Ck)) - feps;
  
  if abs(delta_i) < abs(delta_b)  then
    delta_b = delta_i;
    scale_b = scale_i;
  end
end

CkNew = round(scale_b*Ck);

// adjust the middle coef if error in not null and
// we have an odd number of coefficients
if ((modulo(N,2) == 1) & (delta_b <> 0)) then
  CkNew(1+(N-1)/2) = CkNew(1+(N-1)/2) - delta_b;
end
    
mprintf("Info: Rounded Integer Coeff (sum = %d)\n",sum(CkNew));
mprintf("% 3d % 7d/%d\n",[n;CkNew;linspace(feps,feps,length(n))]');
if  ((sum(CkNew) - feps) <> 0) then
  mprintf("Info: Warning, the residual error is not null, manual adjustment is needed\n");
end


//
// Plot the updated coefficient
//
subplot(1,2,1);
plot(n,CkNew /sum(CkNew),'>');

//
// Plot the updated frequency response
// 
subplot(1,2,2);
//X = linspace(0,1,1024);
[Hrefnew,frnew] = frmag(CkNew/sum(CkNew),1024);
//plot(X',20*log10([Hrefnew])','black');
plot(frnew,20*log10([Hrefnew]),'black');




// Dump for C code cut&paste

for i = [1:length(CkNew)]
  mprintf("%6d,",CkNew(i));
end
mprintf("\n");

