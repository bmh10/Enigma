 ==================
| Enigma Emulation |
 ==================

This was a small project I completed in my second year at Imperial College which emulates an Enigma machine with configurable rotors and plugboard.
For a detailed explanation of how the Enigma machine works visit http://en.wikipedia.org/wiki/Enigma_machine.

To compile the c++ files with g++ in the terminal use:

g++ *.cpp ./enigma

To run the enigma machine use:

./engima <pathToDesiredRotorFile.rot> <pathToDesiredPlugboardFile.pb>


Note that including rotors is optional wheras if you do not want a plugboard to be used you should specifiy the plugboard as 'plugboards/null.pb'.
Also note that the number of rotors can be as many as you like wheras there can only be one plugboard.

Now type some text and press enter. It will be encoded using the rotors and plugboard you specified.

You can also use:

./engima <pathToDesiredRotorFile.rot> <pathToDesiredPlugboardFile.pb> < myTextFile.txt > encryptedTextFile.txt

This will take myTextFile.txt and output the encrypted version to encryptedTextFile.txt

A key feature of the enigma machine is that if you pass text through it and then pass the encrypted text back through, with the same machine configuration, then the output should be the same as the original. This was how messages were passed around during World War II by the Germans, with the machine settings of the sender and receiver being changed in sync so that the message could be encrpted by the sender and easily decrypted by the receive. Of course this meant they had to also keep the agreed machine settings for each day a secret.

I have also included the test file written in Haskell we used if you wish to play with the code and test it out.

To run the testsuite, in this directory run:

./tests.hs <path_to_your_enigma_program>

There are sample rotor configuration files in rotors/
and plugboard configuration files in plugboards/


If you like this why not check out my website at http://www.benhomer.freeiz.com/blog and my other projects on GitHub.

