module halfSubtractor(output reg D,C,input A,B);
always @ (A or B) begin
if((A==1'b0 & B==1'b0)|(A==1'b1 & B==1'b1))
begin
D=1'b0;
end
else
D=1'b1;
if((A==1'b0 & B==1'b1))
begin 
C=1'b1;
end
else
	C=1'b0;
end
endmodule
