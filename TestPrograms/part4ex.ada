procedure test is
  a, b :integer;
  c : boolean;
begin
  loop
     a := 5;
     exit;
     b := a;
   end loop;
   c := true;
   if a = b then
     b := a + a;
   end if;
   b := 2;
end;

