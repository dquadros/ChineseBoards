# Rotating LED DIY Electronic Clock Kit

## English

This is a microcontroller-based clock that displays the time and temperature in a 4-digit display. A ring of 60 LEDs (12 red and 48 blue) is used to display the seconds or visual effects.

The power connector is a mini USB.  A CR1220 battery keeps the time when there is no external power. USB cable, power supply, and battery are not included in the kit.

AliExpress ads contain photos of the finished board and the schematic.

The kit comes with a small piece of paper with a parts list on one side and a schematic on the other — all in Chinese.

Optionally, you can buy a plastic enclosure for the clock.

### Assembly tips

Sort the resistors:

* 3 10k (brown/black/black/red/brown) R9, R10, R11
* 8 330R (orange/orange/black/black/brown) R1 to R8

Pay attention to orientation:

* LEDs: the positive terminal (the longer one) is marked '+' on the board and goes to the external border of the board
* Transistor: follow the marking on the board.
* Buzzer: the positive terminal (the longer one) is marked '+' on the board
* Display: the decimal points go to the bottom, as indicated by the marking on the board.
* DS1220: There is a dot at pin 1 in the chip and the board
* Microcontroller (SRC15W408AS) and socket: follow the marking on the board.

Solder ordering:

  LEDs and the display are mounted on the top side of the board, and the other components are mounted on the back side.**
  
* Solder the DS1220 on the back side if you are using a heating platform.
* Solder the LEDs from the top side. The longer terminal goes to the outside. Red LEDs go at the numbered positions, blue LEDs in the others.
* Mount and solder the back side components:
  	* DS1220 if you are soldering it with a soldering iron
  	* Resistors
  	* Crystal
  	* LDR and thermistor
  	* Capacitors
	* Battery holder
	* Microcontroller socket
	* Transistor
	* Buzzer
	* USB connector
	* Buttons
* Solder the display from the top side

### Operation

Press S2 to circle through the various LED animation options.

Press S1 to enter the configuration mode. In this mode, S2 increments the current option, and S1 advances to the next configuration. The order of the configurations is:

* current time (minutes, hours)
* alarm time (minutes, hours)
* alarm on (1111) or off (0000)
* automatic light intensity on (1111) or off (0000)

### Links

Available at AliExpress: 

https://pt.aliexpress.com/item/1005009707015210.html

### My Comments

This kit is for intermediate builders, as it has one SMD component and many LEDs. The resulting clock is very nice.

## Portugues

Este é um relógio baseado em microcontrolador que exibe a hora e a temperatura em um display de 4 dígitos. Um anel de 60 LEDs (12 vermelhos e 48 azuis) é usado para exibir os segundos ou efeitos visuais.

O conector de alimentação é um mini USB. Uma bateria CR1220 mantém a hora quando não há alimentação externa. Cabo USB, fonte de alimentação e bateria não estão incluídos no kit.

Os anúncios do AliExpress contêm fotos da placa montada e o esquema elétrico.

O kit vem com um pequeno folheto com a lista de peças de um lado e o esquema elétrico do outro — tudo em chinês.

Opcionalmente, você pode comprar uma caixa plástica para o relógio.

### Dicas de Montagem

Separe os resistores:

* 3 resistores de 10kΩ (marrom/preto/preto/vermelho/marrom) R9, R10, R11
* 8 resistores de 330Ω (laranja/laranja/preto/preto/marrom) R1 a R8

Atenção à orientação:

* LEDs: o terminal positivo (o mais comprido) está marcado com '+' na placa e vai na borda externa da placa.
* Transistor: siga a marcação na placa.
* Buzzer: o terminal positivo (o mais comprido) está marcado com '+' na placa.
* Display: os pontos decimais devem ser colocados na parte inferior, conforme indicado pela marcação na placa.
* DS1220: Há um ponto no pino 1 tanto no chip quanto na placa.
* Microcontrolador (SRC15W408AS) e soquete: siga a marcação na placa.

Ordem de soldagem:

  **Os LEDs e o display são montados na parte superior da placa, e os demais componentes são montados na parte inferior.**

* Solde o DS1220 na parte inferior se estiver usando uma plataforma de aquecimento.
* Solde os LEDs pela parte superior. O terminal mais longo fica voltado para fora. Os LEDs vermelhos vão nas posições numeradas e os LEDs azuis nas demais.
* Monte e solde os componentes da parte inferior:
	* DS1220 (se estiver soldando com ferro de solda)
	* Resistores
	* Cristal
	* LDR e termistor
	* Capacitores
	* Suporte para bateria
	* Soquete para microcontrolador
	* Transistor
	* Buzzer
	* Conector USB
	* Botões
	* Solde o display pela parte superior

### Operação

Pressione S2 para percorrer as várias opções de animação do LED.

Pressione S1 para entrar no modo de configuração. Neste modo, S2 incrementa a opção atual e S1 avança para a próxima configuração. A ordem das configurações é:

* hora atual (minutos, horas)
* hora do alarme (minutos, horas)
* alarme ligado (1111) ou desligado (0000)
* intensidade automática da luz ligada (1111) ou desligada (0000)

### Links

Encontrado na AliExpress:

https://pt.aliexpress.com/item/1005009707015210.html

### Meus Comentários

Este kit é para construtores de nível intermediário, pois contém um componente SMD e muitos LEDs. O relógio resultante fica muito bonito.
