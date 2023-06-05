module HALFADDER_BEH(output reg S,C,input A,B);
always @ (A or B)  begin
if((A==1'b0 & B==1'b0) | (A==1'b1 & B==1'b1))
begin
	S=1'b0;
end
else
	S=1'b1;
if(A==1'b1 & B==1'b1)
begin
	C=1'b1;
end
else
	C=1'b0;
end
endmodule
