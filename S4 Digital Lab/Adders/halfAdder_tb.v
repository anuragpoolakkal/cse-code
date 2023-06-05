`include "halfAdder.v"
module HALFADDER_BEH_tb;
reg A,B;
wire S,C;
HALFADDER_BEH i(S,C,A,B);
initial begin
A=0;B=0;
#1 A=0;B=1;
#1 A=1;B=0;
#1 A=1;B=1;
end
initial begin
$monitor("%t | A=%d |B=%d |S=%d |C=%d",$time,A,B,S,C);
$dumpfile("dump.vcd");
$dumpvars();
end
endmodule

