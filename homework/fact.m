% Data Structures
% HW 1.2
% compute factorial from 0 to 50
clear all;

n=input('Please input a number: ');

a=1;
for i=1:n
  a=a*i;
  a=carry(a);
  
  len=length(a);
  str='%2d!=';
  for j=1:len
    str=[str, '%d'];
  end
  str=[str, '\n'];
  fprintf(str, i, fliplr(a));
end
