# AA2_Ajedrez_Jornet_Farre
Activitat de clase del joc Ajedrez.

## Consideracions del codi
Per realitzar el Joc de l'Ajedrez hem utilitzat IA en l'implementacio d'aquestes estructures:
- Hem utilitzat **islower** (per saber si la peça era negra o blanca, ja que islower s'utilitza per verificar si la lletra es minuscula), encara que tambe ho haguesim pogut fer a base de casteos amb la taula ascii.
- També em utilitzat lo mateix pero per a majuscules, **isupper**.
- Hem utilitzat IA al fer el moviment diagonal amb la diferencia del valor absolut (**abs**).
- I en aquest tipus de estructura **"isupper(pieza) ? 1 : -1"** , que tambe es podria representar com a un if y else. Pero en el switch que esta no sabia implemetarlo.
- Tambe he buscat una funcio ya integrada en el switch(), que fa que el switch no sigui keysensitive. **switch(tolower)**.

  ### Altres consideracions
  - No ens ha sortit fer el JAQUE MATE, aixi que hem decidit fer un final alternatiu mes simple, aquest consisteix en que cada equip te un contador inicial de les 16 peces. Cada peça val un punt, aixi que cada eliminacio restara -1 en el contador del altre.
