module xor_gate(output reg Y, input A, input B)
always @(A or B) begin
    if (A != B)
        Y = 1;
    else Y = 0;
end
endmodule