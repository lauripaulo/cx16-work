.org $080D
.segment "STARTUP"
.segment "INIT"
.segment "ONCE"
.segment "CODE"

  jmp start

valor1 = $123
valor2 = $456
total = $579

start:
  clc
  lda #<valor1
  adc #<valor2
  sta $1000
  lda #>valor1
  adc #>valor2
  sta $1001
  lda total
  sta $1003
  rts
