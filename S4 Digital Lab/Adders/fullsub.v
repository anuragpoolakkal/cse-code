module fullsub(output reg D,Bout,input A,B,Cin);
always @ (A or B or Cin) begin
if((A==1'b0 & B==1'b0 & Cin==1'b0)|(A==1'b0 & B==1'b1 & Cin==1'b1)|(A==1'b1 & B==1'b0 & Cin==1'b1)|(A==1'b1 & B==1'b1 & Cin==1'b0))
begin 
D=1'b0;
end
else
D=1'b1;
if((A==1'b0 & B==1'b0 & Cin==1'b0)|(A==1'b1 & B==1'b0 & Cin==1'b0)|(A==1'b1 & B==1'b0 & Cin==1'b1)|(A==1'b1 & B==1'b1 & Cin==1'b0))
begin 
Bout=1'b0;
end
else
Bout=1'b1;
end
endmodule

