module nor_gate(output reg Y, input A, input B)
always @(A or B) begin
        if (A == 0 && B == 0)
            Y = 1;
        else Y = 0;
end
endmodule