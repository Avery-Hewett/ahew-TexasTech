module top(CLK, RST, OP, DATA, ADDR, outA, outB);

input CLK;
input RST;
input[1:0] OP;
input[7:0] DATA;
input[1:0] ADDR;

reg[7:0] regY;
reg[7:0] regX;
reg[7:0] temp;

output reg[7:0] outA;
output reg[7:0] outB;

always @(negedge CLK) begin
  //RST Case
  if(RST == 1) begin
    regX = 0;
    regY = 0;
  end


    if(ADDR == 00) begin
      regX <= DATA;
    end
    if(ADDR == 01)begin
      regY <= DATA;
    end
    if(OP == 01) begin
      regX <= (regX + regY);
    end
    if(OP == 01) begin
      regY <= (regX + regY);
    end
    if(OP == 10) begin
      regX <= (regX - regY);
    end
    if(OP == 10) begin
      regY <= (regX - regY);
    end
    if(ADDR == 00) begin
      outA <= DATA;
    end
    if(ADDR == 00) begin
      outB <= DATA;
    end
    if(OP == 01) begin
      outB <= (regX + regY);
    end
    if(ADDR == 00) begin
      outA <= (regX + regY);
    end
    if(OP == 10) begin
      outB <= (regX - regY);
    end
    if(ADDR == 00) begin
      outA <= (regX - regY);
    end

end

endmodule
