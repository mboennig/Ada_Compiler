procedure main is             --ck3D.ada
   type w is array(4..7) of integer;
   type ranger is range 0 .. 44;
   type rec is record
      A, Z : w;
      X : ranger;
      Q, P, R: integer;
   end record;
   x : integer;
   i : w;
   a, b : integer;
   c, e, ffff, h : integer;
   x : boolean;       --duplicate id should not be inserted in symTab
   u : rec;
   procedure helper is
      a : integer;  --this id okay because new scope
      c : rec;
      bad, error : exception;
      procedure Nest is
         a : ranger;  -- this one is also ok
         z : boolean;
      begin
         null;
      end;

   begin
       a := 3;
       x := 5;
       i(a) := i(2);
       c.Z(a) := u.A(x);
       a := u.Z;
   end;

begin
   helper;
   x := 5;

end;
