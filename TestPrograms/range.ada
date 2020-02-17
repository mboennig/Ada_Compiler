-- range.ada
procedure main is
   b      : integer;
   type Wray is array(1..3) of integer;
   type cool is array(4..7) of Wray;
   type Ranger is range 0 .. 44;
   w : cool;  --5
    a : Ranger; -- 17
    c : Wray;

begin
   w(6)(1) := b;
   b := w(5)(2);
   a := 102;
   b := 114;
   a := b;
   a := c( 4 ) + 2;
   c( a ) := 6;
end;
