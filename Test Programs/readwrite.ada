procedure main is      -- readwrite.ada
        x:integer;
        y:boolean;
begin
        read(x);
        read(y);
        write(x+x,y and y, x * x);
	x := 5;
end;
