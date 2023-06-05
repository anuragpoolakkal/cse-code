`include "halfSub.v"
module HALFSUB_BEH_tb;
reg A,B;
wire D,C;
halfSubtractor i(D,C,A,B);
initial begin
A=0;B=0;
#1 A=0;B=1;
#1 A=1;B=0;
#1 A=1;B=1;
end
initial begin
$monitor("%t | A=%d |B=%d |D=%d |BW=%d",$time,A,B,D,C);
end
endmodule

