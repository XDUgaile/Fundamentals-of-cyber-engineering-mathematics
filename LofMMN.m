function LofMMN(a, s, n)
b=a/s;
former=0;
for k=0:n
    former = former+b^k/factorial(k);
end
P0=(former+b^(n+1)/(n*factorial(n)*(1-b/n)))^(-1);

former=0;
for k=0:n
    former = former+k*b^k/factorial(k);
end
e=0.0001;
latter=0;
largenumber=10000;
for k=1:largenumber
    if(((n+k)*(b/n)^(k-1))<e)break;
    end
    latter=latter+(n+k)*(b/n)^(k-1);
end
latter=latter*b^(n+1)/(n*factorial(n));
L=(former+latter)*P0