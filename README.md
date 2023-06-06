<h1 align="center">LeafCheck - GS_EDGE</h1>
<img src="./GS_EDGE.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
  
## :link: Links
* Tinkercad: https://www.tinkercad.com/things/dQaCf0nBt1P-gsedge/editel?sharecode=nMVkLh-caj5z318ILQlZay0pIa0TP9JnWb0rT-MRWSw
  <br>
* Youtbe: https://youtu.be/rLMBpv8rYBw 


## :memo: Descrição do projeto

* O LeafCheck, oferece uma solução inovadora para os agricultores, detecção e prevenção de doenças de plantas por meio de modelos de IA e aprendizado de máquina, com diagnósticos precisos, orientações de tratamento personalizadas e integração de informações climáticas e geográficas, os agricultores podem agir de forma proativa, detectando precocemente doenças e tomando medidas corretivas adequadas.
  <br>
* Pensando nisso, adequamos nossa ideia para o Arduino. Tentamos reproduzir o que nosso aplicativo fará, no LeafCheck serão utilizadas fotos das plantas para que a Inteligência Artificial analíse e diga ao usuário qual é o estado de saúde de sua planta.
Para ilustrar essa funcionalidade, utilizamos diversos sensores para detectar umidade, temperatura, PH do solo, presença de ervas daninhas e a luminosidade, abrindo e fechando a estufa para o bem estar das plantas. Todas as leituras dos sensores são informadas no display a cada 2 segundos.

## :books: Funcionalidades

* <b>Sensor de umidade</b>: Detecta a umidade do solo
  <br>
* <b>Sensor de temperatura</b>: Detecta temperatura ambiente
  <br>
* <b>Sensor de movimento</b>: Detecta se há ervas daninha no solo
  <br>
* <b>Sensor de PH do solo</b>: Detecta se o nivel de PH do solo está aceitavel
  <br>
* <b>Sensor de luminosidade</b>: Alem de detectar a luminosidade, faz com que o motor abra e feche de acordo com a luminosidade do local, se etiver muito alto ele ativa o motor, se estiver baixa ele é desativado.
  <br>
* <b>Display LCD</b>: Informa os resultados dos sensores de forma prética e direta

## :seedling: Instruções de uso

* Clonar repositório
  <br>
* Colocar o código na IDE Arduino
  <br>
* Fazer as devidas conexões dos sensores, fios e resistores no Arduino Uno R3
  <br>
* Rodar o programa

## :clipboard: Requisitos

* 1 Arduino Uno R3
  <br>
* IDE Arduino
  <br>
* 2 Potenciômetros
  <br>
* 1 Sensor de temperatura
  <br>
* 1 Sensor PIR
  <br>
* 1 Fotorresistor
  <br>
* 1 Micro servo
  <br>
* 1 Display LCD 16x2
  <br>
* 2 Resistores de 10KΩ
  <br>
* Ligação ao computador

## :hammer: Dependências
* Biblioteca Servo para funcionamento do Servo Motor
  <br>
* Biblioteca LiquidCrystal para funcionamento do Display LCD


## :wrench: Tecnologias utilizadas

* Arduino;
  <br>
* C++;
  <br>
* Display lcd;
  <br>
* Potenciometro;
  <br>
* Sensor de temperatura;
  <br>
* Sensor PIR;
  <br>
* Fotorresistor;
  <br>
* Micro servo;


## :handshake: Colaboradores
<table>
  <tr>
    <td align="center">
        <sub>
          <b>Enzo Luiz Goulart - RM99666</b>
          <br>
        </sub>
        <sub>
          <b>Natan Eguchi dos Santos - RM98720</b>
          <br>
        </sub>
        <sub>
          <b>Kayky Paschoal Ribeiro - RM99929</b>
          <br>
        </sub>
        <sub>
          <b>Gustavo Henrique Santos Bonfim - RM98864</b>
          <br>
        </sub>
        <sub>
          <b>Lucas Yuji Farias Umada - RM99757 </b>
          <br>
        </sub>
    </td>
  </tr>
</table>

## :dart: Status do projeto
Concluido :white_check_mark: