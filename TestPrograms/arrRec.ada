-- arrRec.ada

procedure main is
   a : integer;       --offset is 4
   type aType is array (0..2) of integer;  -- size is 3
   type Wray is array(1..3) of integer;
   type cool is array(4..7) of Wray;
   type dateType is record
      month : integer;
      year  : integer;   --could change this to be type aType!
      crap : aType;
   end record;                             -- size is 2
   arr  : aType;      --offset is 5
   b    : integer;    --offset is 8
   date : dateType;   --offset is 9
   c    : integer;    --offset is 11
                      --size of AR is 12 (4 + 1+3+1+2+1)
   w: cool;
   procedure green is
      c : integer;    --offset is 4
   begin
      c := arr (2);
      w(5)(2) := c;
      c := w(5)(2);
      c := arr ( date.month );
   end;

begin
   a := 1;
   a := w(4)(1);
   w(7)(3) := c;
   
   --date.month := 4;
   arr(a) := date.year;
   date.month := 4;
   c := arr ( date.month );
end;
