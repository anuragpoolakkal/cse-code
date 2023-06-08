`include "fullSub.v"
module fullSub_tb;
reg A,B,Cin;
wire D,Bout;
fullsub i(D,Bout,A,B,Cin);
initial begin
A=0;B=0;Cin=0;
#1 A=0;B=0;Cin=1;
#1 A=0;B=1;Cin=0;
#1 A=0;B=1;Cin=1;
#1 A=1;B=0;Cin=0;
#1 A=1;B=0;Cin=1;
#1 A=1;B=1;Cin=0;
#1 A=1;B=1;Cin=1;
end
initial begin
$monitor("%t | A=%d |B=%d |S=%d |C=%d",$time,A,B,D,Bout);
end
endmodule


