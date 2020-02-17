--nestLoop.ada

procedure main is
        a,b,c:integer;
        d: integer;

begin
        loop
           a := 5;
           loop
               b := d;
               exit when b > a;
           end loop;
           d := 4;
        end loop;  --yes this is an infinite loop
end;               --but your job as compiler is
                   --just to translate
