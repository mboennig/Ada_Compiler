-- RecNested.ada
--tests if a compiler can handle nested records
procedure Main is
   type Appointment is record
      Day : integer;  --offset from appointment is 0
      Time : integer; --offset from appointment is 1
   end record;      --size is 2

   type ApptList is array (0..4) of Appointment;
   --size is (5*2)=10

   type Schedule is record
      Tasks : ApptList;
      --offset is 0 from schedule's offset
      ATask : Appointment;
      --offset is 10 from schedule's offset
   end record; --size is (10+2) = 12
   W : integer;
   NonLocS : ApptList;   --offset is 4
   C       : integer;    --offset is 16
                         --size of AR is 17 = (4+12+1)
   procedure Other is
      LocalS : ApptList; --offset 4
      B, C, A :integer;  --offset 14
   begin
        A := LocalS(1).Time;
	B := NonLocS(2).Day;
	LocalS(4).Time := 10;
	NonLocS(0).Day := 88;
	--A := LocalS.Tasks(3).Time;
      --NonLocS.Tasks(3).Time := 800;
      A := 660;
   end;

begin
   C := 360;
   Other;
end;
