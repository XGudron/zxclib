10 PRINT "128k banks loader"
20 CLEAR 32767 : REM Update RAMTOP
30 POKE 23388, 0 +16:REM Update BANK_M system cell to bank 0
40 OUT 32765, 0 +16:REM Switch to bank 0
50 LOAD "" CODE 49152 :REM load into 0xC000
60 POKE 23388, 1 +16:REM Update BANK_M system cell to bank 1
70 OUT 32765, 1 +16:REM Switch to bank 1
80 LOAD "" CODE 49152 :REM load into 0xC000
90 POKE 23388, 0 +16:REM Update BANK_M system cell to bank 0
100 OUT 32765, 0 +16:REM Switch to bank 0 (main)
110 LOAD "" CODE 32768 :REM load main program
120 RANDOMIZE USR 32768 :REM jump to program
