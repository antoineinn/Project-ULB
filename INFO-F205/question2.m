%Antoine Innocent BA2 Informatique

%Question2
figure
n=100;
dmax=2^-24;
d=(0:n-1)/(n-1)*dmax;
x=(1-exp(-d.^2))./d;
subplot(2,1,1)
plot(d,x,'LineWidth',3)
title('Graphique initial')


x=(1-exp(-2.*d.^2))./((1+exp(-d.^2)).*d);
subplot(2,1,2)
plot(d,x,'LineWidth',3);
title('Graphique de l''expression équivalente')



%QUESTION1
%n=100;
%dmax=10^(-3);
%d=(0:n-1)/(n-1)*dmax;
%x=(1-exp(-d.^2))./d;
%plot(d,x,'LineWidth',3);
%title('Graphique de la fonction F(d) sur l''intervalle [0,0.001]')


%QUESTION3
%n=100;
%dmax=2^-24;
%d=(0:n-1)/(n-1)*dmax;

%res=d;
%for j=0:9; 
  
%    res=res.*(1+exp(-2**j*d.**2));
  
%end;



%x=(1-exp(-2**10*d.**2))./res;
%plot(d,x,'LineWidth',3)
%title('Graphique de la version itérative')
