module top(A, B, Add, Load, CLK, ClrN);


  //Data input
  input[7:0] A;

  //Control input
  input Load;
  input Add;
  input CLK;
  input ClrN;

  //Data output
  output reg [7:0] B;

  always @(posedge CLK)
  begin
    if(ClrN == 0)
      B = 0;
    if(Load == 1)
      B = A;
    if(Add == 1)
      B = A+B;
  end

endmodule
