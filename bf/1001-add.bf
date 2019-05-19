,         read character and store it in cell #1
>         move pointer to cell #2 (second byte)
,         read character and store it in cell #2
[           enter loop
    <       move to cell #1
    +       increment cell #1
    >       move to cell #2
    -       decrement cell #2
]           we exit the loop when the last cell is 0
<       go back to cell #1
------------------------------------------------ subtract 48 (ie ASCII char code of '0')
.       print cell #1
