-- nestIF.ada

procedure fool is
   a : integer;       --offset is 4
   d : integer;       --offset is 5
   b : integer;       --offset is 6
                      --size of AR is 7 (4+1+1+1)
begin
   a := 5 ** 2;
   loop
      exit;
   end loop;
   if a = b then
      if a = b then
         null;
      end if;
      a := d;
      d := 5;
   end if;
end;
