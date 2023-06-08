module not_gate(output Y, input A);
always @(A) begin
    if (A == 0)
        Y = 0;
    else Y = 1;
end
endmodule
