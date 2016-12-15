% mymagic(N) create an N by N magic square
% mymagic() works as buil-in Matlab function magic()
% magic() sign up sequence to upper right
% mymagic() sign up sequence to upper left

function m=mymagic(n)
m=zeros(n);
i=1; j=fix((1+n)/2);


for k=1:n^2
   exist=(m(i,j) ~= 0);
   if (exist)
     i=i+2; j=j+1;
     i(i == n+1)=1;
     i(i == n+2)=2;
     j(j == n+1)=1;
     m(i,j)=k;
   else
     m(i,j)=k;
   end
   i=i-1; j=j-1;
   i(i == 0)=n; j(j == 0)=n;
end
