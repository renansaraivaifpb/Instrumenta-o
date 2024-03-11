# Write and read of values varied by a potentiometer

I developed a simulation of circuit eletronic in Tinkercard plataform (Figure 1).

## Figure 1 - Circuit.

![title](circuito.png)

## Source: Author.

And the assembly can be seen in the figure 2.

## Figure 2 - Assembly of circuit.

![title](assembly_circuit.png)

## 2.a) led off.

![title](assembly_circuit2.png)

## 2.b) led on.
Source: Author.

The etap write values in file txt was used arduino + software known Miners Rogers. Where Miners can conect with serial of arduino and obtain the values registred for them saves in file txt.

The read was developed in Scilab, you are can review code in file code.c

Plotting values, we can see in figure 3.

## Figure 3 - Plotting values in scilab.

![Graph](graph.png)

## Source: Author.

Why values are in interval between 0 - 255?
Becaus was realized transform in code: ```valor_lido = map(analogRead(potenciometro),0,1023,0,255);```
The value was read and re-mapping to sign 0 and 5V.
