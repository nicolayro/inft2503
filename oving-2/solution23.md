# Øving 2: Pekere of referanser

### Oppgave 2
'Line' blir satt til å være en nullptr, som er bra, men problemet er at kompilatoren ikke vet hvor mye plass
den skal sette av i minne. Når vi da prøver å kopiere sette inn en hel setning, er det ikke plass.
Vi får segmentation fault ved kjøring

### Oppgave 3
Vi setter av plass til 5 chars, så dersom brukeren skriver flere enn fem tegn kan det blir tull.
Videre, hvis det som skrives ikke inneholder en 'e' vil programmet fortsette nedover i minne og se etter en 'e' her. 
Til slutt vil man starte å lete utenfor pekeren og inn i vilkårlig minne. 

