--nestLoopDeep.ada
procedure main is
a,b:integer;
begin
  loop
    exit;
    a := 5;
    exit;
    loop
       exit;
       b := 7;
       loop
          exit;
          a := 1;
          exit;
       end loop;
       exit;
   end loop;
   a := 4;
   exit;
   end loop;
end;
