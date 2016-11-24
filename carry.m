% carry function make sure there is only one digit store in an element of factorial array 

function arr=carry(a)

while(sum(fix(a/10))>=1)
    right0=0;
    for j=1:length(a)
      left=mod(a(j),10);
      right=fix(a(j)/10);
      a(j)=right0+left;
      if (j==length(a) && right>=1)
        a=[a, right];
      end
      right0=right;
    end
end

arr=a;
