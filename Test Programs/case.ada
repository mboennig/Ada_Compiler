--case.ada

procedure main is
   a, b, c :integer;

begin
   case a is
      when 14 => a := a + 1;
                 b := a;
      when 31 => a := 22;
      when 44 =>
                 case b+2 is
                    when 1 | 2 | 3 => b := 57;
                    when 16        => read(b);
                    when others    => write(a);
                 end case;
      when 53 => b := 42;
   end case;
   c := 76;
end;

