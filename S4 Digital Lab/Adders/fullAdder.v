module fulladder(output reg S,C,input A,B,Cin);
always @ (A or B or Cin) begin
if((A==1'b0 & B==1'b0 & Cin==1'b0)|(A==1'b0 & B==1'b1 & Cin==1'b1)|(A==1'b1 & B==1'b0 & Cin==1'b1)|(A==1'b1 & B==1'b1 & Cin==1'b0))
begin 
S=1'b0;
end
else
S=1'b1;
if((A==1'b0 & B==1'b0 & Cin==1'b0)|(A==1'b0 & B==1'b0 & Cin==1'b1)|(A==1'b0 & B==1'b1 & Cin==1'b0)|(A==1'b1 & B==1'b0 & Cin==1'b0))
begin 
C=1'b0;
end
else
C=1'b1;
end
endmodule

