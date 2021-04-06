module top (A, B, C, Y);

  // Data inputs
  input[3:0] A;
  input[3:0] B;

  // Control input
  input C;

  // Data output
  output[3:0] Y;
  reg[3:0] Y;

  always @(A or B or C or Y)
  begin
    if(C == 0)
      Y = A+B;
    else
      Y = A-B;
  end

endmodule
