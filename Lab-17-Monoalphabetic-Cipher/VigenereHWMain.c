#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include "cipher.h"

int main(int argc, char *argv[]) {
    // char bucket1[1000000];
    // char bucket2[1000000];
    // char bucket3[1000000];
    // char bucket4[1000000];

    // char encrypted[1000000];
    // char BUFF[1000000];
    // char decrypted[1000000];

    // double lowest_distance = 1000000;
    // double temp_distance = 0;
    // double temp_reversed_distance = 0;
    // FILE *file;

    // file = fopen(argv[1], "r");
    // if (file == NULL) {
    //     printf("%s\n", strerror(errno));
    //     exit(errno);
    //     return 0;
    // }

    // while (fgets(BUFF, 999999, file) != NULL) {
    //     strcat(encrypted, BUFF);
    // }
    // fclose(file);

    // for (int i = 0; i < strlen(encrypted); i++) {
    //     if (i % 4 == 0) {
    //         bucket1[i / 4] = encrypted[i];
    //     }
    //     else if (i % 4 == 1) {
    //         bucket2[i / 4] = encrypted[i];
    //     }
    //     else if (i % 4 == 2) {
    //         bucket3[i / 4] = encrypted[i];
    //     }
    //     else if (i % 4 == 3) {
    //         bucket4[i / 4] = encrypted[i];
    //     }
    // }
    // printf("%s\n\n", bucket1);
    // printf("%s\n\n", bucket2);
    // printf("%s\n\n", bucket3);
    // printf("%s\n\n", bucket4);

    char decrypted[1000000];
    char bucket1[1000000] = "CMHLEROENWGCLVLLNNNUAONRUTTSOOTGWDLUIESHTPOELIAAFVOHLAEAGCUIHVFMLOGMUETEEIARLVEMUEEIYFOTLUGOONESNINTEFRNLEDELHVYOTHPHOTIQETGAIPOVMOLRLENTEENTILONOSSTIOIGMGOAOITISTTRTNLTHSIFRCTWMFNSDIYEHIESHSRNTIETWLTMNIGSTOHHSRATAENODEATTEIUSRYHNTBEUYRADISORSMERDWHUIAEHRSEWRDEEOOSBEHTNEEADAAODREIFOPIWOFHLLAEWFEZTE";
    char bucket2[1000000] = "AEMSYSNRDLPIYIIEOEMRNTGTLOETNRHHOSATTAEEEAFWDSYVDIFEENGTTILOEEIYFWGATMHNRSMIYERYLNRNSILAYSBRFWHEDNGHAEYEITECLEEHSSAPAFHTUSRMLNLPEEMIAYPGOSEDHCYCGPHOHAUTHEESSNCHSUIEPODLHIOCLIAHSSUHWIETTEPRNIUIGHFYKIMAETRROIREEHYRHMEGWSONHHNSRUCOEHOEDNWVSISBRECESOSIERGNFEETYAWIXMWWTAREHOMISBVNOBESCEUROEUSTAOTCDWREH";
    char bucket3[1000000] = "LIAOEAEMHORSHNTOMYYSDHPIAIRMSEOTUABATNEWRRTOIAIERNFSEDUIHRANNRNSGIRBTOWEIAPZNMISWEIDENURPIEEFAOSBGUERVFRMASIYNRYGUNENMARIAOOPCERNFDBTSPITTTMOAKKPLAFECNHTTTESAAIMBTFILBWALPAOSTRHEPIOQTAOSTEONRSIITBNTOLNHDEMMORRVNLEELSATCWMEOYILIFMAELRDHEIALYAEORUUITRFHDTSEAOTATTENNHTYRABOSHYEDLYEWHWREURTIONOTRSAGRE";
    char bucket4[1000000] = "LSEMAGVIONEEAGTROIPENIACRNEEHIUILIOLLDTAYTHRTWHOIGTPNRLNECTWEIDERNIOHUHVTDDZOBNOHVFMLVNIANFCIRUARIPROEUAENPAWEMPECURDETERSNRRITETREEETINHRAEDLNIEETFNCTIIOTAOSNSYSUOSAAIPOHLUHOOILOSRULKTHHITGPINSHUEASLIEEEEETCIEEYSFITRHEIERWONATTATSTOBASNNECLFMCRNTHSRTLTTTKUERSRDTIETWETLLWEWSCEBZHAHSVSEOGFDKHOOTASR";
    char oneChar[2];
    oneChar[1] = '\0';

    for (int i = 0; i < strlen(bucket1); i++) {
        oneChar[0] = bucket1[i];
        strcat(decrypted, oneChar);
        oneChar[0] = bucket2[i];
        strcat(decrypted, oneChar);
        oneChar[0] = bucket3[i];
        strcat(decrypted, oneChar);
        oneChar[0] = bucket4[i];
        strcat(decrypted, oneChar);
    }

    // printf("Decrypted: %s\n", decrypted);

    char key1 = 'D' - ('D' - decrypted[0] + 1);
    char key2 = 'V' - decrypted[1] + 'A';
    char key3 = 'Y' - decrypted[2] +'A';
    char key4 = 'C' + 26 - decrypted[3] + 'A';
    printf("%c%c%c%c\n", key1, key2, key3, key4);
}