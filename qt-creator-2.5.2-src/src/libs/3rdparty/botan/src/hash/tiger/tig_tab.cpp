/*
* S-Box Tables for Tiger
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#include <botan/tiger.h>

namespace Botan {

const u64bit Tiger::SBOX1[256] = {
   (u64bit) 0x02AAB17CF7E90C5EULL, (u64bit) 0xAC424B03E243A8ECULL, (u64bit) 0x72CD5BE30DD5FCD3ULL,
   (u64bit) 0x6D019B93F6F97F3AULL, (u64bit) 0xCD9978FFD21F9193ULL, (u64bit) 0x7573A1C9708029E2ULL,
   (u64bit) 0xB164326B922A83C3ULL, (u64bit) 0x46883EEE04915870ULL, (u64bit) 0xEAACE3057103ECE6ULL,
   (u64bit) 0xC54169B808A3535CULL, (u64bit) 0x4CE754918DDEC47CULL, (u64bit) 0x0AA2F4DFDC0DF40CULL,
   (u64bit) 0x10B76F18A74DBEFAULL, (u64bit) 0xC6CCB6235AD1AB6AULL, (u64bit) 0x13726121572FE2FFULL,
   (u64bit) 0x1A488C6F199D921EULL, (u64bit) 0x4BC9F9F4DA0007CAULL, (u64bit) 0x26F5E6F6E85241C7ULL,
   (u64bit) 0x859079DBEA5947B6ULL, (u64bit) 0x4F1885C5C99E8C92ULL, (u64bit) 0xD78E761EA96F864BULL,
   (u64bit) 0x8E36428C52B5C17DULL, (u64bit) 0x69CF6827373063C1ULL, (u64bit) 0xB607C93D9BB4C56EULL,
   (u64bit) 0x7D820E760E76B5EAULL, (u64bit) 0x645C9CC6F07FDC42ULL, (u64bit) 0xBF38A078243342E0ULL,
   (u64bit) 0x5F6B343C9D2E7D04ULL, (u64bit) 0xF2C28AEB600B0EC6ULL, (u64bit) 0x6C0ED85F7254BCACULL,
   (u64bit) 0x71592281A4DB4FE5ULL, (u64bit) 0x1967FA69CE0FED9FULL, (u64bit) 0xFD5293F8B96545DBULL,
   (u64bit) 0xC879E9D7F2A7600BULL, (u64bit) 0x860248920193194EULL, (u64bit) 0xA4F9533B2D9CC0B3ULL,
   (u64bit) 0x9053836C15957613ULL, (u64bit) 0xDB6DCF8AFC357BF1ULL, (u64bit) 0x18BEEA7A7A370F57ULL,
   (u64bit) 0x037117CA50B99066ULL, (u64bit) 0x6AB30A9774424A35ULL, (u64bit) 0xF4E92F02E325249BULL,
   (u64bit) 0x7739DB07061CCAE1ULL, (u64bit) 0xD8F3B49CECA42A05ULL, (u64bit) 0xBD56BE3F51382F73ULL,
   (u64bit) 0x45FAED5843B0BB28ULL, (u64bit) 0x1C813D5C11BF1F83ULL, (u64bit) 0x8AF0E4B6D75FA169ULL,
   (u64bit) 0x33EE18A487AD9999ULL, (u64bit) 0x3C26E8EAB1C94410ULL, (u64bit) 0xB510102BC0A822F9ULL,
   (u64bit) 0x141EEF310CE6123BULL, (u64bit) 0xFC65B90059DDB154ULL, (u64bit) 0xE0158640C5E0E607ULL,
   (u64bit) 0x884E079826C3A3CFULL, (u64bit) 0x930D0D9523C535FDULL, (u64bit) 0x35638D754E9A2B00ULL,
   (u64bit) 0x4085FCCF40469DD5ULL, (u64bit) 0xC4B17AD28BE23A4CULL, (u64bit) 0xCAB2F0FC6A3E6A2EULL,
   (u64bit) 0x2860971A6B943FCDULL, (u64bit) 0x3DDE6EE212E30446ULL, (u64bit) 0x6222F32AE01765AEULL,
   (u64bit) 0x5D550BB5478308FEULL, (u64bit) 0xA9EFA98DA0EDA22AULL, (u64bit) 0xC351A71686C40DA7ULL,
   (u64bit) 0x1105586D9C867C84ULL, (u64bit) 0xDCFFEE85FDA22853ULL, (u64bit) 0xCCFBD0262C5EEF76ULL,
   (u64bit) 0xBAF294CB8990D201ULL, (u64bit) 0xE69464F52AFAD975ULL, (u64bit) 0x94B013AFDF133E14ULL,
   (u64bit) 0x06A7D1A32823C958ULL, (u64bit) 0x6F95FE5130F61119ULL, (u64bit) 0xD92AB34E462C06C0ULL,
   (u64bit) 0xED7BDE33887C71D2ULL, (u64bit) 0x79746D6E6518393EULL, (u64bit) 0x5BA419385D713329ULL,
   (u64bit) 0x7C1BA6B948A97564ULL, (u64bit) 0x31987C197BFDAC67ULL, (u64bit) 0xDE6C23C44B053D02ULL,
   (u64bit) 0x581C49FED002D64DULL, (u64bit) 0xDD474D6338261571ULL, (u64bit) 0xAA4546C3E473D062ULL,
   (u64bit) 0x928FCE349455F860ULL, (u64bit) 0x48161BBACAAB94D9ULL, (u64bit) 0x63912430770E6F68ULL,
   (u64bit) 0x6EC8A5E602C6641CULL, (u64bit) 0x87282515337DDD2BULL, (u64bit) 0x2CDA6B42034B701BULL,
   (u64bit) 0xB03D37C181CB096DULL, (u64bit) 0xE108438266C71C6FULL, (u64bit) 0x2B3180C7EB51B255ULL,
   (u64bit) 0xDF92B82F96C08BBCULL, (u64bit) 0x5C68C8C0A632F3BAULL, (u64bit) 0x5504CC861C3D0556ULL,
   (u64bit) 0xABBFA4E55FB26B8FULL, (u64bit) 0x41848B0AB3BACEB4ULL, (u64bit) 0xB334A273AA445D32ULL,
   (u64bit) 0xBCA696F0A85AD881ULL, (u64bit) 0x24F6EC65B528D56CULL, (u64bit) 0x0CE1512E90F4524AULL,
   (u64bit) 0x4E9DD79D5506D35AULL, (u64bit) 0x258905FAC6CE9779ULL, (u64bit) 0x2019295B3E109B33ULL,
   (u64bit) 0xF8A9478B73A054CCULL, (u64bit) 0x2924F2F934417EB0ULL, (u64bit) 0x3993357D536D1BC4ULL,
   (u64bit) 0x38A81AC21DB6FF8BULL, (u64bit) 0x47C4FBF17D6016BFULL, (u64bit) 0x1E0FAADD7667E3F5ULL,
   (u64bit) 0x7ABCFF62938BEB96ULL, (u64bit) 0xA78DAD948FC179C9ULL, (u64bit) 0x8F1F98B72911E50DULL,
   (u64bit) 0x61E48EAE27121A91ULL, (u64bit) 0x4D62F7AD31859808ULL, (u64bit) 0xECEBA345EF5CEAEBULL,
   (u64bit) 0xF5CEB25EBC9684CEULL, (u64bit) 0xF633E20CB7F76221ULL, (u64bit) 0xA32CDF06AB8293E4ULL,
   (u64bit) 0x985A202CA5EE2CA4ULL, (u64bit) 0xCF0B8447CC8A8FB1ULL, (u64bit) 0x9F765244979859A3ULL,
   (u64bit) 0xA8D516B1A1240017ULL, (u64bit) 0x0BD7BA3EBB5DC726ULL, (u64bit) 0xE54BCA55B86ADB39ULL,
   (u64bit) 0x1D7A3AFD6C478063ULL, (u64bit) 0x519EC608E7669EDDULL, (u64bit) 0x0E5715A2D149AA23ULL,
   (u64bit) 0x177D4571848FF194ULL, (u64bit) 0xEEB55F3241014C22ULL, (u64bit) 0x0F5E5CA13A6E2EC2ULL,
   (u64bit) 0x8029927B75F5C361ULL, (u64bit) 0xAD139FABC3D6E436ULL, (u64bit) 0x0D5DF1A94CCF402FULL,
   (u64bit) 0x3E8BD948BEA5DFC8ULL, (u64bit) 0xA5A0D357BD3FF77EULL, (u64bit) 0xA2D12E251F74F645ULL,
   (u64bit) 0x66FD9E525E81A082ULL, (u64bit) 0x2E0C90CE7F687A49ULL, (u64bit) 0xC2E8BCBEBA973BC5ULL,
   (u64bit) 0x000001BCE509745FULL, (u64bit) 0x423777BBE6DAB3D6ULL, (u64bit) 0xD1661C7EAEF06EB5ULL,
   (u64bit) 0xA1781F354DAACFD8ULL, (u64bit) 0x2D11284A2B16AFFCULL, (u64bit) 0xF1FC4F67FA891D1FULL,
   (u64bit) 0x73ECC25DCB920ADAULL, (u64bit) 0xAE610C22C2A12651ULL, (u64bit) 0x96E0A810D356B78AULL,
   (u64bit) 0x5A9A381F2FE7870FULL, (u64bit) 0xD5AD62EDE94E5530ULL, (u64bit) 0xD225E5E8368D1427ULL,
   (u64bit) 0x65977B70C7AF4631ULL, (u64bit) 0x99F889B2DE39D74FULL, (u64bit) 0x233F30BF54E1D143ULL,
   (u64bit) 0x9A9675D3D9A63C97ULL, (u64bit) 0x5470554FF334F9A8ULL, (u64bit) 0x166ACB744A4F5688ULL,
   (u64bit) 0x70C74CAAB2E4AEADULL, (u64bit) 0xF0D091646F294D12ULL, (u64bit) 0x57B82A89684031D1ULL,
   (u64bit) 0xEFD95A5A61BE0B6BULL, (u64bit) 0x2FBD12E969F2F29AULL, (u64bit) 0x9BD37013FEFF9FE8ULL,
   (u64bit) 0x3F9B0404D6085A06ULL, (u64bit) 0x4940C1F3166CFE15ULL, (u64bit) 0x09542C4DCDF3DEFBULL,
   (u64bit) 0xB4C5218385CD5CE3ULL, (u64bit) 0xC935B7DC4462A641ULL, (u64bit) 0x3417F8A68ED3B63FULL,
   (u64bit) 0xB80959295B215B40ULL, (u64bit) 0xF99CDAEF3B8C8572ULL, (u64bit) 0x018C0614F8FCB95DULL,
   (u64bit) 0x1B14ACCD1A3ACDF3ULL, (u64bit) 0x84D471F200BB732DULL, (u64bit) 0xC1A3110E95E8DA16ULL,
   (u64bit) 0x430A7220BF1A82B8ULL, (u64bit) 0xB77E090D39DF210EULL, (u64bit) 0x5EF4BD9F3CD05E9DULL,
   (u64bit) 0x9D4FF6DA7E57A444ULL, (u64bit) 0xDA1D60E183D4A5F8ULL, (u64bit) 0xB287C38417998E47ULL,
   (u64bit) 0xFE3EDC121BB31886ULL, (u64bit) 0xC7FE3CCC980CCBEFULL, (u64bit) 0xE46FB590189BFD03ULL,
   (u64bit) 0x3732FD469A4C57DCULL, (u64bit) 0x7EF700A07CF1AD65ULL, (u64bit) 0x59C64468A31D8859ULL,
   (u64bit) 0x762FB0B4D45B61F6ULL, (u64bit) 0x155BAED099047718ULL, (u64bit) 0x68755E4C3D50BAA6ULL,
   (u64bit) 0xE9214E7F22D8B4DFULL, (u64bit) 0x2ADDBF532EAC95F4ULL, (u64bit) 0x32AE3909B4BD0109ULL,
   (u64bit) 0x834DF537B08E3450ULL, (u64bit) 0xFA209DA84220728DULL, (u64bit) 0x9E691D9B9EFE23F7ULL,
   (u64bit) 0x0446D288C4AE8D7FULL, (u64bit) 0x7B4CC524E169785BULL, (u64bit) 0x21D87F0135CA1385ULL,
   (u64bit) 0xCEBB400F137B8AA5ULL, (u64bit) 0x272E2B66580796BEULL, (u64bit) 0x3612264125C2B0DEULL,
   (u64bit) 0x057702BDAD1EFBB2ULL, (u64bit) 0xD4BABB8EACF84BE9ULL, (u64bit) 0x91583139641BC67BULL,
   (u64bit) 0x8BDC2DE08036E024ULL, (u64bit) 0x603C8156F49F68EDULL, (u64bit) 0xF7D236F7DBEF5111ULL,
   (u64bit) 0x9727C4598AD21E80ULL, (u64bit) 0xA08A0896670A5FD7ULL, (u64bit) 0xCB4A8F4309EBA9CBULL,
   (u64bit) 0x81AF564B0F7036A1ULL, (u64bit) 0xC0B99AA778199ABDULL, (u64bit) 0x959F1EC83FC8E952ULL,
   (u64bit) 0x8C505077794A81B9ULL, (u64bit) 0x3ACAAF8F056338F0ULL, (u64bit) 0x07B43F50627A6778ULL,
   (u64bit) 0x4A44AB49F5ECCC77ULL, (u64bit) 0x3BC3D6E4B679EE98ULL, (u64bit) 0x9CC0D4D1CF14108CULL,
   (u64bit) 0x4406C00B206BC8A0ULL, (u64bit) 0x82A18854C8D72D89ULL, (u64bit) 0x67E366B35C3C432CULL,
   (u64bit) 0xB923DD61102B37F2ULL, (u64bit) 0x56AB2779D884271DULL, (u64bit) 0xBE83E1B0FF1525AFULL,
   (u64bit) 0xFB7C65D4217E49A9ULL, (u64bit) 0x6BDBE0E76D48E7D4ULL, (u64bit) 0x08DF828745D9179EULL,
   (u64bit) 0x22EA6A9ADD53BD34ULL, (u64bit) 0xE36E141C5622200AULL, (u64bit) 0x7F805D1B8CB750EEULL,
   (u64bit) 0xAFE5C7A59F58E837ULL, (u64bit) 0xE27F996A4FB1C23CULL, (u64bit) 0xD3867DFB0775F0D0ULL,
   (u64bit) 0xD0E673DE6E88891AULL, (u64bit) 0x123AEB9EAFB86C25ULL, (u64bit) 0x30F1D5D5C145B895ULL,
   (u64bit) 0xBB434A2DEE7269E7ULL, (u64bit) 0x78CB67ECF931FA38ULL, (u64bit) 0xF33B0372323BBF9CULL,
   (u64bit) 0x52D66336FB279C74ULL, (u64bit) 0x505F33AC0AFB4EAAULL, (u64bit) 0xE8A5CD99A2CCE187ULL,
   (u64bit) 0x534974801E2D30BBULL, (u64bit) 0x8D2D5711D5876D90ULL, (u64bit) 0x1F1A412891BC038EULL,
   (u64bit) 0xD6E2E71D82E56648ULL, (u64bit) 0x74036C3A497732B7ULL, (u64bit) 0x89B67ED96361F5ABULL,
   (u64bit) 0xFFED95D8F1EA02A2ULL, (u64bit) 0xE72B3BD61464D43DULL, (u64bit) 0xA6300F170BDC4820ULL,
   (u64bit) 0xEBC18760ED78A77AULL };

const u64bit Tiger::SBOX2[256] = {
   (u64bit) 0xE6A6BE5A05A12138ULL, (u64bit) 0xB5A122A5B4F87C98ULL, (u64bit) 0x563C6089140B6990ULL,
   (u64bit) 0x4C46CB2E391F5DD5ULL, (u64bit) 0xD932ADDBC9B79434ULL, (u64bit) 0x08EA70E42015AFF5ULL,
   (u64bit) 0xD765A6673E478CF1ULL, (u64bit) 0xC4FB757EAB278D99ULL, (u64bit) 0xDF11C6862D6E0692ULL,
   (u64bit) 0xDDEB84F10D7F3B16ULL, (u64bit) 0x6F2EF604A665EA04ULL, (u64bit) 0x4A8E0F0FF0E0DFB3ULL,
   (u64bit) 0xA5EDEEF83DBCBA51ULL, (u64bit) 0xFC4F0A2A0EA4371EULL, (u64bit) 0xE83E1DA85CB38429ULL,
   (u64bit) 0xDC8FF882BA1B1CE2ULL, (u64bit) 0xCD45505E8353E80DULL, (u64bit) 0x18D19A00D4DB0717ULL,
   (u64bit) 0x34A0CFEDA5F38101ULL, (u64bit) 0x0BE77E518887CAF2ULL, (u64bit) 0x1E341438B3C45136ULL,
   (u64bit) 0xE05797F49089CCF9ULL, (u64bit) 0xFFD23F9DF2591D14ULL, (u64bit) 0x543DDA228595C5CDULL,
   (u64bit) 0x661F81FD99052A33ULL, (u64bit) 0x8736E641DB0F7B76ULL, (u64bit) 0x15227725418E5307ULL,
   (u64bit) 0xE25F7F46162EB2FAULL, (u64bit) 0x48A8B2126C13D9FEULL, (u64bit) 0xAFDC541792E76EEAULL,
   (u64bit) 0x03D912BFC6D1898FULL, (u64bit) 0x31B1AAFA1B83F51BULL, (u64bit) 0xF1AC2796E42AB7D9ULL,
   (u64bit) 0x40A3A7D7FCD2EBACULL, (u64bit) 0x1056136D0AFBBCC5ULL, (u64bit) 0x7889E1DD9A6D0C85ULL,
   (u64bit) 0xD33525782A7974AAULL, (u64bit) 0xA7E25D09078AC09BULL, (u64bit) 0xBD4138B3EAC6EDD0ULL,
   (u64bit) 0x920ABFBE71EB9E70ULL, (u64bit) 0xA2A5D0F54FC2625CULL, (u64bit) 0xC054E36B0B1290A3ULL,
   (u64bit) 0xF6DD59FF62FE932BULL, (u64bit) 0x3537354511A8AC7DULL, (u64bit) 0xCA845E9172FADCD4ULL,
   (u64bit) 0x84F82B60329D20DCULL, (u64bit) 0x79C62CE1CD672F18ULL, (u64bit) 0x8B09A2ADD124642CULL,
   (u64bit) 0xD0C1E96A19D9E726ULL, (u64bit) 0x5A786A9B4BA9500CULL, (u64bit) 0x0E020336634C43F3ULL,
   (u64bit) 0xC17B474AEB66D822ULL, (u64bit) 0x6A731AE3EC9BAAC2ULL, (u64bit) 0x8226667AE0840258ULL,
   (u64bit) 0x67D4567691CAECA5ULL, (u64bit) 0x1D94155C4875ADB5ULL, (u64bit) 0x6D00FD985B813FDFULL,
   (u64bit) 0x51286EFCB774CD06ULL, (u64bit) 0x5E8834471FA744AFULL, (u64bit) 0xF72CA0AEE761AE2EULL,
   (u64bit) 0xBE40E4CDAEE8E09AULL, (u64bit) 0xE9970BBB5118F665ULL, (u64bit) 0x726E4BEB33DF1964ULL,
   (u64bit) 0x703B000729199762ULL, (u64bit) 0x4631D816F5EF30A7ULL, (u64bit) 0xB880B5B51504A6BEULL,
   (u64bit) 0x641793C37ED84B6CULL, (u64bit) 0x7B21ED77F6E97D96ULL, (u64bit) 0x776306312EF96B73ULL,
   (u64bit) 0xAE528948E86FF3F4ULL, (u64bit) 0x53DBD7F286A3F8F8ULL, (u64bit) 0x16CADCE74CFC1063ULL,
   (u64bit) 0x005C19BDFA52C6DDULL, (u64bit) 0x68868F5D64D46AD3ULL, (u64bit) 0x3A9D512CCF1E186AULL,
   (u64bit) 0x367E62C2385660AEULL, (u64bit) 0xE359E7EA77DCB1D7ULL, (u64bit) 0x526C0773749ABE6EULL,
   (u64bit) 0x735AE5F9D09F734BULL, (u64bit) 0x493FC7CC8A558BA8ULL, (u64bit) 0xB0B9C1533041AB45ULL,
   (u64bit) 0x321958BA470A59BDULL, (u64bit) 0x852DB00B5F46C393ULL, (u64bit) 0x91209B2BD336B0E5ULL,
   (u64bit) 0x6E604F7D659EF19FULL, (u64bit) 0xB99A8AE2782CCB24ULL, (u64bit) 0xCCF52AB6C814C4C7ULL,
   (u64bit) 0x4727D9AFBE11727BULL, (u64bit) 0x7E950D0C0121B34DULL, (u64bit) 0x756F435670AD471FULL,
   (u64bit) 0xF5ADD442615A6849ULL, (u64bit) 0x4E87E09980B9957AULL, (u64bit) 0x2ACFA1DF50AEE355ULL,
   (u64bit) 0xD898263AFD2FD556ULL, (u64bit) 0xC8F4924DD80C8FD6ULL, (u64bit) 0xCF99CA3D754A173AULL,
   (u64bit) 0xFE477BACAF91BF3CULL, (u64bit) 0xED5371F6D690C12DULL, (u64bit) 0x831A5C285E687094ULL,
   (u64bit) 0xC5D3C90A3708A0A4ULL, (u64bit) 0x0F7F903717D06580ULL, (u64bit) 0x19F9BB13B8FDF27FULL,
   (u64bit) 0xB1BD6F1B4D502843ULL, (u64bit) 0x1C761BA38FFF4012ULL, (u64bit) 0x0D1530C4E2E21F3BULL,
   (u64bit) 0x8943CE69A7372C8AULL, (u64bit) 0xE5184E11FEB5CE66ULL, (u64bit) 0x618BDB80BD736621ULL,
   (u64bit) 0x7D29BAD68B574D0BULL, (u64bit) 0x81BB613E25E6FE5BULL, (u64bit) 0x071C9C10BC07913FULL,
   (u64bit) 0xC7BEEB7909AC2D97ULL, (u64bit) 0xC3E58D353BC5D757ULL, (u64bit) 0xEB017892F38F61E8ULL,
   (u64bit) 0xD4EFFB9C9B1CC21AULL, (u64bit) 0x99727D26F494F7ABULL, (u64bit) 0xA3E063A2956B3E03ULL,
   (u64bit) 0x9D4A8B9A4AA09C30ULL, (u64bit) 0x3F6AB7D500090FB4ULL, (u64bit) 0x9CC0F2A057268AC0ULL,
   (u64bit) 0x3DEE9D2DEDBF42D1ULL, (u64bit) 0x330F49C87960A972ULL, (u64bit) 0xC6B2720287421B41ULL,
   (u64bit) 0x0AC59EC07C00369CULL, (u64bit) 0xEF4EAC49CB353425ULL, (u64bit) 0xF450244EEF0129D8ULL,
   (u64bit) 0x8ACC46E5CAF4DEB6ULL, (u64bit) 0x2FFEAB63989263F7ULL, (u64bit) 0x8F7CB9FE5D7A4578ULL,
   (u64bit) 0x5BD8F7644E634635ULL, (u64bit) 0x427A7315BF2DC900ULL, (u64bit) 0x17D0C4AA2125261CULL,
   (u64bit) 0x3992486C93518E50ULL, (u64bit) 0xB4CBFEE0A2D7D4C3ULL, (u64bit) 0x7C75D6202C5DDD8DULL,
   (u64bit) 0xDBC295D8E35B6C61ULL, (u64bit) 0x60B369D302032B19ULL, (u64bit) 0xCE42685FDCE44132ULL,
   (u64bit) 0x06F3DDB9DDF65610ULL, (u64bit) 0x8EA4D21DB5E148F0ULL, (u64bit) 0x20B0FCE62FCD496FULL,
   (u64bit) 0x2C1B912358B0EE31ULL, (u64bit) 0xB28317B818F5A308ULL, (u64bit) 0xA89C1E189CA6D2CFULL,
   (u64bit) 0x0C6B18576AAADBC8ULL, (u64bit) 0xB65DEAA91299FAE3ULL, (u64bit) 0xFB2B794B7F1027E7ULL,
   (u64bit) 0x04E4317F443B5BEBULL, (u64bit) 0x4B852D325939D0A6ULL, (u64bit) 0xD5AE6BEEFB207FFCULL,
   (u64bit) 0x309682B281C7D374ULL, (u64bit) 0xBAE309A194C3B475ULL, (u64bit) 0x8CC3F97B13B49F05ULL,
   (u64bit) 0x98A9422FF8293967ULL, (u64bit) 0x244B16B01076FF7CULL, (u64bit) 0xF8BF571C663D67EEULL,
   (u64bit) 0x1F0D6758EEE30DA1ULL, (u64bit) 0xC9B611D97ADEB9B7ULL, (u64bit) 0xB7AFD5887B6C57A2ULL,
   (u64bit) 0x6290AE846B984FE1ULL, (u64bit) 0x94DF4CDEACC1A5FDULL, (u64bit) 0x058A5BD1C5483AFFULL,
   (u64bit) 0x63166CC142BA3C37ULL, (u64bit) 0x8DB8526EB2F76F40ULL, (u64bit) 0xE10880036F0D6D4EULL,
   (u64bit) 0x9E0523C9971D311DULL, (u64bit) 0x45EC2824CC7CD691ULL, (u64bit) 0x575B8359E62382C9ULL,
   (u64bit) 0xFA9E400DC4889995ULL, (u64bit) 0xD1823ECB45721568ULL, (u64bit) 0xDAFD983B8206082FULL,
   (u64bit) 0xAA7D29082386A8CBULL, (u64bit) 0x269FCD4403B87588ULL, (u64bit) 0x1B91F5F728BDD1E0ULL,
   (u64bit) 0xE4669F39040201F6ULL, (u64bit) 0x7A1D7C218CF04ADEULL, (u64bit) 0x65623C29D79CE5CEULL,
   (u64bit) 0x2368449096C00BB1ULL, (u64bit) 0xAB9BF1879DA503BAULL, (u64bit) 0xBC23ECB1A458058EULL,
   (u64bit) 0x9A58DF01BB401ECCULL, (u64bit) 0xA070E868A85F143DULL, (u64bit) 0x4FF188307DF2239EULL,
   (u64bit) 0x14D565B41A641183ULL, (u64bit) 0xEE13337452701602ULL, (u64bit) 0x950E3DCF3F285E09ULL,
   (u64bit) 0x59930254B9C80953ULL, (u64bit) 0x3BF299408930DA6DULL, (u64bit) 0xA955943F53691387ULL,
   (u64bit) 0xA15EDECAA9CB8784ULL, (u64bit) 0x29142127352BE9A0ULL, (u64bit) 0x76F0371FFF4E7AFBULL,
   (u64bit) 0x0239F450274F2228ULL, (u64bit) 0xBB073AF01D5E868BULL, (u64bit) 0xBFC80571C10E96C1ULL,
   (u64bit) 0xD267088568222E23ULL, (u64bit) 0x9671A3D48E80B5B0ULL, (u64bit) 0x55B5D38AE193BB81ULL,
   (u64bit) 0x693AE2D0A18B04B8ULL, (u64bit) 0x5C48B4ECADD5335FULL, (u64bit) 0xFD743B194916A1CAULL,
   (u64bit) 0x2577018134BE98C4ULL, (u64bit) 0xE77987E83C54A4ADULL, (u64bit) 0x28E11014DA33E1B9ULL,
   (u64bit) 0x270CC59E226AA213ULL, (u64bit) 0x71495F756D1A5F60ULL, (u64bit) 0x9BE853FB60AFEF77ULL,
   (u64bit) 0xADC786A7F7443DBFULL, (u64bit) 0x0904456173B29A82ULL, (u64bit) 0x58BC7A66C232BD5EULL,
   (u64bit) 0xF306558C673AC8B2ULL, (u64bit) 0x41F639C6B6C9772AULL, (u64bit) 0x216DEFE99FDA35DAULL,
   (u64bit) 0x11640CC71C7BE615ULL, (u64bit) 0x93C43694565C5527ULL, (u64bit) 0xEA038E6246777839ULL,
   (u64bit) 0xF9ABF3CE5A3E2469ULL, (u64bit) 0x741E768D0FD312D2ULL, (u64bit) 0x0144B883CED652C6ULL,
   (u64bit) 0xC20B5A5BA33F8552ULL, (u64bit) 0x1AE69633C3435A9DULL, (u64bit) 0x97A28CA4088CFDECULL,
   (u64bit) 0x8824A43C1E96F420ULL, (u64bit) 0x37612FA66EEEA746ULL, (u64bit) 0x6B4CB165F9CF0E5AULL,
   (u64bit) 0x43AA1C06A0ABFB4AULL, (u64bit) 0x7F4DC26FF162796BULL, (u64bit) 0x6CBACC8E54ED9B0FULL,
   (u64bit) 0xA6B7FFEFD2BB253EULL, (u64bit) 0x2E25BC95B0A29D4FULL, (u64bit) 0x86D6A58BDEF1388CULL,
   (u64bit) 0xDED74AC576B6F054ULL, (u64bit) 0x8030BDBC2B45805DULL, (u64bit) 0x3C81AF70E94D9289ULL,
   (u64bit) 0x3EFF6DDA9E3100DBULL, (u64bit) 0xB38DC39FDFCC8847ULL, (u64bit) 0x123885528D17B87EULL,
   (u64bit) 0xF2DA0ED240B1B642ULL, (u64bit) 0x44CEFADCD54BF9A9ULL, (u64bit) 0x1312200E433C7EE6ULL,
   (u64bit) 0x9FFCC84F3A78C748ULL, (u64bit) 0xF0CD1F72248576BBULL, (u64bit) 0xEC6974053638CFE4ULL,
   (u64bit) 0x2BA7B67C0CEC4E4CULL, (u64bit) 0xAC2F4DF3E5CE32EDULL, (u64bit) 0xCB33D14326EA4C11ULL,
   (u64bit) 0xA4E9044CC77E58BCULL, (u64bit) 0x5F513293D934FCEFULL, (u64bit) 0x5DC9645506E55444ULL,
   (u64bit) 0x50DE418F317DE40AULL, (u64bit) 0x388CB31A69DDE259ULL, (u64bit) 0x2DB4A83455820A86ULL,
   (u64bit) 0x9010A91E84711AE9ULL, (u64bit) 0x4DF7F0B7B1498371ULL, (u64bit) 0xD62A2EABC0977179ULL,
   (u64bit) 0x22FAC097AA8D5C0EULL };

const u64bit Tiger::SBOX3[256] = {
   (u64bit) 0xF49FCC2FF1DAF39BULL, (u64bit) 0x487FD5C66FF29281ULL, (u64bit) 0xE8A30667FCDCA83FULL,
   (u64bit) 0x2C9B4BE3D2FCCE63ULL, (u64bit) 0xDA3FF74B93FBBBC2ULL, (u64bit) 0x2FA165D2FE70BA66ULL,
   (u64bit) 0xA103E279970E93D4ULL, (u64bit) 0xBECDEC77B0E45E71ULL, (u64bit) 0xCFB41E723985E497ULL,
   (u64bit) 0xB70AAA025EF75017ULL, (u64bit) 0xD42309F03840B8E0ULL, (u64bit) 0x8EFC1AD035898579ULL,
   (u64bit) 0x96C6920BE2B2ABC5ULL, (u64bit) 0x66AF4163375A9172ULL, (u64bit) 0x2174ABDCCA7127FBULL,
   (u64bit) 0xB33CCEA64A72FF41ULL, (u64bit) 0xF04A4933083066A5ULL, (u64bit) 0x8D970ACDD7289AF5ULL,
   (u64bit) 0x8F96E8E031C8C25EULL, (u64bit) 0xF3FEC02276875D47ULL, (u64bit) 0xEC7BF310056190DDULL,
   (u64bit) 0xF5ADB0AEBB0F1491ULL, (u64bit) 0x9B50F8850FD58892ULL, (u64bit) 0x4975488358B74DE8ULL,
   (u64bit) 0xA3354FF691531C61ULL, (u64bit) 0x0702BBE481D2C6EEULL, (u64bit) 0x89FB24057DEDED98ULL,
   (u64bit) 0xAC3075138596E902ULL, (u64bit) 0x1D2D3580172772EDULL, (u64bit) 0xEB738FC28E6BC30DULL,
   (u64bit) 0x5854EF8F63044326ULL, (u64bit) 0x9E5C52325ADD3BBEULL, (u64bit) 0x90AA53CF325C4623ULL,
   (u64bit) 0xC1D24D51349DD067ULL, (u64bit) 0x2051CFEEA69EA624ULL, (u64bit) 0x13220F0A862E7E4FULL,
   (u64bit) 0xCE39399404E04864ULL, (u64bit) 0xD9C42CA47086FCB7ULL, (u64bit) 0x685AD2238A03E7CCULL,
   (u64bit) 0x066484B2AB2FF1DBULL, (u64bit) 0xFE9D5D70EFBF79ECULL, (u64bit) 0x5B13B9DD9C481854ULL,
   (u64bit) 0x15F0D475ED1509ADULL, (u64bit) 0x0BEBCD060EC79851ULL, (u64bit) 0xD58C6791183AB7F8ULL,
   (u64bit) 0xD1187C5052F3EEE4ULL, (u64bit) 0xC95D1192E54E82FFULL, (u64bit) 0x86EEA14CB9AC6CA2ULL,
   (u64bit) 0x3485BEB153677D5DULL, (u64bit) 0xDD191D781F8C492AULL, (u64bit) 0xF60866BAA784EBF9ULL,
   (u64bit) 0x518F643BA2D08C74ULL, (u64bit) 0x8852E956E1087C22ULL, (u64bit) 0xA768CB8DC410AE8DULL,
   (u64bit) 0x38047726BFEC8E1AULL, (u64bit) 0xA67738B4CD3B45AAULL, (u64bit) 0xAD16691CEC0DDE19ULL,
   (u64bit) 0xC6D4319380462E07ULL, (u64bit) 0xC5A5876D0BA61938ULL, (u64bit) 0x16B9FA1FA58FD840ULL,
   (u64bit) 0x188AB1173CA74F18ULL, (u64bit) 0xABDA2F98C99C021FULL, (u64bit) 0x3E0580AB134AE816ULL,
   (u64bit) 0x5F3B05B773645ABBULL, (u64bit) 0x2501A2BE5575F2F6ULL, (u64bit) 0x1B2F74004E7E8BA9ULL,
   (u64bit) 0x1CD7580371E8D953ULL, (u64bit) 0x7F6ED89562764E30ULL, (u64bit) 0xB15926FF596F003DULL,
   (u64bit) 0x9F65293DA8C5D6B9ULL, (u64bit) 0x6ECEF04DD690F84CULL, (u64bit) 0x4782275FFF33AF88ULL,
   (u64bit) 0xE41433083F820801ULL, (u64bit) 0xFD0DFE409A1AF9B5ULL, (u64bit) 0x4325A3342CDB396BULL,
   (u64bit) 0x8AE77E62B301B252ULL, (u64bit) 0xC36F9E9F6655615AULL, (u64bit) 0x85455A2D92D32C09ULL,
   (u64bit) 0xF2C7DEA949477485ULL, (u64bit) 0x63CFB4C133A39EBAULL, (u64bit) 0x83B040CC6EBC5462ULL,
   (u64bit) 0x3B9454C8FDB326B0ULL, (u64bit) 0x56F56A9E87FFD78CULL, (u64bit) 0x2DC2940D99F42BC6ULL,
   (u64bit) 0x98F7DF096B096E2DULL, (u64bit) 0x19A6E01E3AD852BFULL, (u64bit) 0x42A99CCBDBD4B40BULL,
   (u64bit) 0xA59998AF45E9C559ULL, (u64bit) 0x366295E807D93186ULL, (u64bit) 0x6B48181BFAA1F773ULL,
   (u64bit) 0x1FEC57E2157A0A1DULL, (u64bit) 0x4667446AF6201AD5ULL, (u64bit) 0xE615EBCACFB0F075ULL,
   (u64bit) 0xB8F31F4F68290778ULL, (u64bit) 0x22713ED6CE22D11EULL, (u64bit) 0x3057C1A72EC3C93BULL,
   (u64bit) 0xCB46ACC37C3F1F2FULL, (u64bit) 0xDBB893FD02AAF50EULL, (u64bit) 0x331FD92E600B9FCFULL,
   (u64bit) 0xA498F96148EA3AD6ULL, (u64bit) 0xA8D8426E8B6A83EAULL, (u64bit) 0xA089B274B7735CDCULL,
   (u64bit) 0x87F6B3731E524A11ULL, (u64bit) 0x118808E5CBC96749ULL, (u64bit) 0x9906E4C7B19BD394ULL,
   (u64bit) 0xAFED7F7E9B24A20CULL, (u64bit) 0x6509EADEEB3644A7ULL, (u64bit) 0x6C1EF1D3E8EF0EDEULL,
   (u64bit) 0xB9C97D43E9798FB4ULL, (u64bit) 0xA2F2D784740C28A3ULL, (u64bit) 0x7B8496476197566FULL,
   (u64bit) 0x7A5BE3E6B65F069DULL, (u64bit) 0xF96330ED78BE6F10ULL, (u64bit) 0xEEE60DE77A076A15ULL,
   (u64bit) 0x2B4BEE4AA08B9BD0ULL, (u64bit) 0x6A56A63EC7B8894EULL, (u64bit) 0x02121359BA34FEF4ULL,
   (u64bit) 0x4CBF99F8283703FCULL, (u64bit) 0x398071350CAF30C8ULL, (u64bit) 0xD0A77A89F017687AULL,
   (u64bit) 0xF1C1A9EB9E423569ULL, (u64bit) 0x8C7976282DEE8199ULL, (u64bit) 0x5D1737A5DD1F7ABDULL,
   (u64bit) 0x4F53433C09A9FA80ULL, (u64bit) 0xFA8B0C53DF7CA1D9ULL, (u64bit) 0x3FD9DCBC886CCB77ULL,
   (u64bit) 0xC040917CA91B4720ULL, (u64bit) 0x7DD00142F9D1DCDFULL, (u64bit) 0x8476FC1D4F387B58ULL,
   (u64bit) 0x23F8E7C5F3316503ULL, (u64bit) 0x032A2244E7E37339ULL, (u64bit) 0x5C87A5D750F5A74BULL,
   (u64bit) 0x082B4CC43698992EULL, (u64bit) 0xDF917BECB858F63CULL, (u64bit) 0x3270B8FC5BF86DDAULL,
   (u64bit) 0x10AE72BB29B5DD76ULL, (u64bit) 0x576AC94E7700362BULL, (u64bit) 0x1AD112DAC61EFB8FULL,
   (u64bit) 0x691BC30EC5FAA427ULL, (u64bit) 0xFF246311CC327143ULL, (u64bit) 0x3142368E30E53206ULL,
   (u64bit) 0x71380E31E02CA396ULL, (u64bit) 0x958D5C960AAD76F1ULL, (u64bit) 0xF8D6F430C16DA536ULL,
   (u64bit) 0xC8FFD13F1BE7E1D2ULL, (u64bit) 0x7578AE66004DDBE1ULL, (u64bit) 0x05833F01067BE646ULL,
   (u64bit) 0xBB34B5AD3BFE586DULL, (u64bit) 0x095F34C9A12B97F0ULL, (u64bit) 0x247AB64525D60CA8ULL,
   (u64bit) 0xDCDBC6F3017477D1ULL, (u64bit) 0x4A2E14D4DECAD24DULL, (u64bit) 0xBDB5E6D9BE0A1EEBULL,
   (u64bit) 0x2A7E70F7794301ABULL, (u64bit) 0xDEF42D8A270540FDULL, (u64bit) 0x01078EC0A34C22C1ULL,
   (u64bit) 0xE5DE511AF4C16387ULL, (u64bit) 0x7EBB3A52BD9A330AULL, (u64bit) 0x77697857AA7D6435ULL,
   (u64bit) 0x004E831603AE4C32ULL, (u64bit) 0xE7A21020AD78E312ULL, (u64bit) 0x9D41A70C6AB420F2ULL,
   (u64bit) 0x28E06C18EA1141E6ULL, (u64bit) 0xD2B28CBD984F6B28ULL, (u64bit) 0x26B75F6C446E9D83ULL,
   (u64bit) 0xBA47568C4D418D7FULL, (u64bit) 0xD80BADBFE6183D8EULL, (u64bit) 0x0E206D7F5F166044ULL,
   (u64bit) 0xE258A43911CBCA3EULL, (u64bit) 0x723A1746B21DC0BCULL, (u64bit) 0xC7CAA854F5D7CDD3ULL,
   (u64bit) 0x7CAC32883D261D9CULL, (u64bit) 0x7690C26423BA942CULL, (u64bit) 0x17E55524478042B8ULL,
   (u64bit) 0xE0BE477656A2389FULL, (u64bit) 0x4D289B5E67AB2DA0ULL, (u64bit) 0x44862B9C8FBBFD31ULL,
   (u64bit) 0xB47CC8049D141365ULL, (u64bit) 0x822C1B362B91C793ULL, (u64bit) 0x4EB14655FB13DFD8ULL,
   (u64bit) 0x1ECBBA0714E2A97BULL, (u64bit) 0x6143459D5CDE5F14ULL, (u64bit) 0x53A8FBF1D5F0AC89ULL,
   (u64bit) 0x97EA04D81C5E5B00ULL, (u64bit) 0x622181A8D4FDB3F3ULL, (u64bit) 0xE9BCD341572A1208ULL,
   (u64bit) 0x1411258643CCE58AULL, (u64bit) 0x9144C5FEA4C6E0A4ULL, (u64bit) 0x0D33D06565CF620FULL,
   (u64bit) 0x54A48D489F219CA1ULL, (u64bit) 0xC43E5EAC6D63C821ULL, (u64bit) 0xA9728B3A72770DAFULL,
   (u64bit) 0xD7934E7B20DF87EFULL, (u64bit) 0xE35503B61A3E86E5ULL, (u64bit) 0xCAE321FBC819D504ULL,
   (u64bit) 0x129A50B3AC60BFA6ULL, (u64bit) 0xCD5E68EA7E9FB6C3ULL, (u64bit) 0xB01C90199483B1C7ULL,
   (u64bit) 0x3DE93CD5C295376CULL, (u64bit) 0xAED52EDF2AB9AD13ULL, (u64bit) 0x2E60F512C0A07884ULL,
   (u64bit) 0xBC3D86A3E36210C9ULL, (u64bit) 0x35269D9B163951CEULL, (u64bit) 0x0C7D6E2AD0CDB5FAULL,
   (u64bit) 0x59E86297D87F5733ULL, (u64bit) 0x298EF221898DB0E7ULL, (u64bit) 0x55000029D1A5AA7EULL,
   (u64bit) 0x8BC08AE1B5061B45ULL, (u64bit) 0xC2C31C2B6C92703AULL, (u64bit) 0x94CC596BAF25EF42ULL,
   (u64bit) 0x0A1D73DB22540456ULL, (u64bit) 0x04B6A0F9D9C4179AULL, (u64bit) 0xEFFDAFA2AE3D3C60ULL,
   (u64bit) 0xF7C8075BB49496C4ULL, (u64bit) 0x9CC5C7141D1CD4E3ULL, (u64bit) 0x78BD1638218E5534ULL,
   (u64bit) 0xB2F11568F850246AULL, (u64bit) 0xEDFABCFA9502BC29ULL, (u64bit) 0x796CE5F2DA23051BULL,
   (u64bit) 0xAAE128B0DC93537CULL, (u64bit) 0x3A493DA0EE4B29AEULL, (u64bit) 0xB5DF6B2C416895D7ULL,
   (u64bit) 0xFCABBD25122D7F37ULL, (u64bit) 0x70810B58105DC4B1ULL, (u64bit) 0xE10FDD37F7882A90ULL,
   (u64bit) 0x524DCAB5518A3F5CULL, (u64bit) 0x3C9E85878451255BULL, (u64bit) 0x4029828119BD34E2ULL,
   (u64bit) 0x74A05B6F5D3CECCBULL, (u64bit) 0xB610021542E13ECAULL, (u64bit) 0x0FF979D12F59E2ACULL,
   (u64bit) 0x6037DA27E4F9CC50ULL, (u64bit) 0x5E92975A0DF1847DULL, (u64bit) 0xD66DE190D3E623FEULL,
   (u64bit) 0x5032D6B87B568048ULL, (u64bit) 0x9A36B7CE8235216EULL, (u64bit) 0x80272A7A24F64B4AULL,
   (u64bit) 0x93EFED8B8C6916F7ULL, (u64bit) 0x37DDBFF44CCE1555ULL, (u64bit) 0x4B95DB5D4B99BD25ULL,
   (u64bit) 0x92D3FDA169812FC0ULL, (u64bit) 0xFB1A4A9A90660BB6ULL, (u64bit) 0x730C196946A4B9B2ULL,
   (u64bit) 0x81E289AA7F49DA68ULL, (u64bit) 0x64669A0F83B1A05FULL, (u64bit) 0x27B3FF7D9644F48BULL,
   (u64bit) 0xCC6B615C8DB675B3ULL, (u64bit) 0x674F20B9BCEBBE95ULL, (u64bit) 0x6F31238275655982ULL,
   (u64bit) 0x5AE488713E45CF05ULL, (u64bit) 0xBF619F9954C21157ULL, (u64bit) 0xEABAC46040A8EAE9ULL,
   (u64bit) 0x454C6FE9F2C0C1CDULL, (u64bit) 0x419CF6496412691CULL, (u64bit) 0xD3DC3BEF265B0F70ULL,
   (u64bit) 0x6D0E60F5C3578A9EULL };

const u64bit Tiger::SBOX4[256] = {
   (u64bit) 0x5B0E608526323C55ULL, (u64bit) 0x1A46C1A9FA1B59F5ULL, (u64bit) 0xA9E245A17C4C8FFAULL,
   (u64bit) 0x65CA5159DB2955D7ULL, (u64bit) 0x05DB0A76CE35AFC2ULL, (u64bit) 0x81EAC77EA9113D45ULL,
   (u64bit) 0x528EF88AB6AC0A0DULL, (u64bit) 0xA09EA253597BE3FFULL, (u64bit) 0x430DDFB3AC48CD56ULL,
   (u64bit) 0xC4B3A67AF45CE46FULL, (u64bit) 0x4ECECFD8FBE2D05EULL, (u64bit) 0x3EF56F10B39935F0ULL,
   (u64bit) 0x0B22D6829CD619C6ULL, (u64bit) 0x17FD460A74DF2069ULL, (u64bit) 0x6CF8CC8E8510ED40ULL,
   (u64bit) 0xD6C824BF3A6ECAA7ULL, (u64bit) 0x61243D581A817049ULL, (u64bit) 0x048BACB6BBC163A2ULL,
   (u64bit) 0xD9A38AC27D44CC32ULL, (u64bit) 0x7FDDFF5BAAF410ABULL, (u64bit) 0xAD6D495AA804824BULL,
   (u64bit) 0xE1A6A74F2D8C9F94ULL, (u64bit) 0xD4F7851235DEE8E3ULL, (u64bit) 0xFD4B7F886540D893ULL,
   (u64bit) 0x247C20042AA4BFDAULL, (u64bit) 0x096EA1C517D1327CULL, (u64bit) 0xD56966B4361A6685ULL,
   (u64bit) 0x277DA5C31221057DULL, (u64bit) 0x94D59893A43ACFF7ULL, (u64bit) 0x64F0C51CCDC02281ULL,
   (u64bit) 0x3D33BCC4FF6189DBULL, (u64bit) 0xE005CB184CE66AF1ULL, (u64bit) 0xFF5CCD1D1DB99BEAULL,
   (u64bit) 0xB0B854A7FE42980FULL, (u64bit) 0x7BD46A6A718D4B9FULL, (u64bit) 0xD10FA8CC22A5FD8CULL,
   (u64bit) 0xD31484952BE4BD31ULL, (u64bit) 0xC7FA975FCB243847ULL, (u64bit) 0x4886ED1E5846C407ULL,
   (u64bit) 0x28CDDB791EB70B04ULL, (u64bit) 0xC2B00BE2F573417FULL, (u64bit) 0x5C9590452180F877ULL,
   (u64bit) 0x7A6BDDFFF370EB00ULL, (u64bit) 0xCE509E38D6D9D6A4ULL, (u64bit) 0xEBEB0F00647FA702ULL,
   (u64bit) 0x1DCC06CF76606F06ULL, (u64bit) 0xE4D9F28BA286FF0AULL, (u64bit) 0xD85A305DC918C262ULL,
   (u64bit) 0x475B1D8732225F54ULL, (u64bit) 0x2D4FB51668CCB5FEULL, (u64bit) 0xA679B9D9D72BBA20ULL,
   (u64bit) 0x53841C0D912D43A5ULL, (u64bit) 0x3B7EAA48BF12A4E8ULL, (u64bit) 0x781E0E47F22F1DDFULL,
   (u64bit) 0xEFF20CE60AB50973ULL, (u64bit) 0x20D261D19DFFB742ULL, (u64bit) 0x16A12B03062A2E39ULL,
   (u64bit) 0x1960EB2239650495ULL, (u64bit) 0x251C16FED50EB8B8ULL, (u64bit) 0x9AC0C330F826016EULL,
   (u64bit) 0xED152665953E7671ULL, (u64bit) 0x02D63194A6369570ULL, (u64bit) 0x5074F08394B1C987ULL,
   (u64bit) 0x70BA598C90B25CE1ULL, (u64bit) 0x794A15810B9742F6ULL, (u64bit) 0x0D5925E9FCAF8C6CULL,
   (u64bit) 0x3067716CD868744EULL, (u64bit) 0x910AB077E8D7731BULL, (u64bit) 0x6A61BBDB5AC42F61ULL,
   (u64bit) 0x93513EFBF0851567ULL, (u64bit) 0xF494724B9E83E9D5ULL, (u64bit) 0xE887E1985C09648DULL,
   (u64bit) 0x34B1D3C675370CFDULL, (u64bit) 0xDC35E433BC0D255DULL, (u64bit) 0xD0AAB84234131BE0ULL,
   (u64bit) 0x08042A50B48B7EAFULL, (u64bit) 0x9997C4EE44A3AB35ULL, (u64bit) 0x829A7B49201799D0ULL,
   (u64bit) 0x263B8307B7C54441ULL, (u64bit) 0x752F95F4FD6A6CA6ULL, (u64bit) 0x927217402C08C6E5ULL,
   (u64bit) 0x2A8AB754A795D9EEULL, (u64bit) 0xA442F7552F72943DULL, (u64bit) 0x2C31334E19781208ULL,
   (u64bit) 0x4FA98D7CEAEE6291ULL, (u64bit) 0x55C3862F665DB309ULL, (u64bit) 0xBD0610175D53B1F3ULL,
   (u64bit) 0x46FE6CB840413F27ULL, (u64bit) 0x3FE03792DF0CFA59ULL, (u64bit) 0xCFE700372EB85E8FULL,
   (u64bit) 0xA7BE29E7ADBCE118ULL, (u64bit) 0xE544EE5CDE8431DDULL, (u64bit) 0x8A781B1B41F1873EULL,
   (u64bit) 0xA5C94C78A0D2F0E7ULL, (u64bit) 0x39412E2877B60728ULL, (u64bit) 0xA1265EF3AFC9A62CULL,
   (u64bit) 0xBCC2770C6A2506C5ULL, (u64bit) 0x3AB66DD5DCE1CE12ULL, (u64bit) 0xE65499D04A675B37ULL,
   (u64bit) 0x7D8F523481BFD216ULL, (u64bit) 0x0F6F64FCEC15F389ULL, (u64bit) 0x74EFBE618B5B13C8ULL,
   (u64bit) 0xACDC82B714273E1DULL, (u64bit) 0xDD40BFE003199D17ULL, (u64bit) 0x37E99257E7E061F8ULL,
   (u64bit) 0xFA52626904775AAAULL, (u64bit) 0x8BBBF63A463D56F9ULL, (u64bit) 0xF0013F1543A26E64ULL,
   (u64bit) 0xA8307E9F879EC898ULL, (u64bit) 0xCC4C27A4150177CCULL, (u64bit) 0x1B432F2CCA1D3348ULL,
   (u64bit) 0xDE1D1F8F9F6FA013ULL, (u64bit) 0x606602A047A7DDD6ULL, (u64bit) 0xD237AB64CC1CB2C7ULL,
   (u64bit) 0x9B938E7225FCD1D3ULL, (u64bit) 0xEC4E03708E0FF476ULL, (u64bit) 0xFEB2FBDA3D03C12DULL,
   (u64bit) 0xAE0BCED2EE43889AULL, (u64bit) 0x22CB8923EBFB4F43ULL, (u64bit) 0x69360D013CF7396DULL,
   (u64bit) 0x855E3602D2D4E022ULL, (u64bit) 0x073805BAD01F784CULL, (u64bit) 0x33E17A133852F546ULL,
   (u64bit) 0xDF4874058AC7B638ULL, (u64bit) 0xBA92B29C678AA14AULL, (u64bit) 0x0CE89FC76CFAADCDULL,
   (u64bit) 0x5F9D4E0908339E34ULL, (u64bit) 0xF1AFE9291F5923B9ULL, (u64bit) 0x6E3480F60F4A265FULL,
   (u64bit) 0xEEBF3A2AB29B841CULL, (u64bit) 0xE21938A88F91B4ADULL, (u64bit) 0x57DFEFF845C6D3C3ULL,
   (u64bit) 0x2F006B0BF62CAAF2ULL, (u64bit) 0x62F479EF6F75EE78ULL, (u64bit) 0x11A55AD41C8916A9ULL,
   (u64bit) 0xF229D29084FED453ULL, (u64bit) 0x42F1C27B16B000E6ULL, (u64bit) 0x2B1F76749823C074ULL,
   (u64bit) 0x4B76ECA3C2745360ULL, (u64bit) 0x8C98F463B91691BDULL, (u64bit) 0x14BCC93CF1ADE66AULL,
   (u64bit) 0x8885213E6D458397ULL, (u64bit) 0x8E177DF0274D4711ULL, (u64bit) 0xB49B73B5503F2951ULL,
   (u64bit) 0x10168168C3F96B6BULL, (u64bit) 0x0E3D963B63CAB0AEULL, (u64bit) 0x8DFC4B5655A1DB14ULL,
   (u64bit) 0xF789F1356E14DE5CULL, (u64bit) 0x683E68AF4E51DAC1ULL, (u64bit) 0xC9A84F9D8D4B0FD9ULL,
   (u64bit) 0x3691E03F52A0F9D1ULL, (u64bit) 0x5ED86E46E1878E80ULL, (u64bit) 0x3C711A0E99D07150ULL,
   (u64bit) 0x5A0865B20C4E9310ULL, (u64bit) 0x56FBFC1FE4F0682EULL, (u64bit) 0xEA8D5DE3105EDF9BULL,
   (u64bit) 0x71ABFDB12379187AULL, (u64bit) 0x2EB99DE1BEE77B9CULL, (u64bit) 0x21ECC0EA33CF4523ULL,
   (u64bit) 0x59A4D7521805C7A1ULL, (u64bit) 0x3896F5EB56AE7C72ULL, (u64bit) 0xAA638F3DB18F75DCULL,
   (u64bit) 0x9F39358DABE9808EULL, (u64bit) 0xB7DEFA91C00B72ACULL, (u64bit) 0x6B5541FD62492D92ULL,
   (u64bit) 0x6DC6DEE8F92E4D5BULL, (u64bit) 0x353F57ABC4BEEA7EULL, (u64bit) 0x735769D6DA5690CEULL,
   (u64bit) 0x0A234AA642391484ULL, (u64bit) 0xF6F9508028F80D9DULL, (u64bit) 0xB8E319A27AB3F215ULL,
   (u64bit) 0x31AD9C1151341A4DULL, (u64bit) 0x773C22A57BEF5805ULL, (u64bit) 0x45C7561A07968633ULL,
   (u64bit) 0xF913DA9E249DBE36ULL, (u64bit) 0xDA652D9B78A64C68ULL, (u64bit) 0x4C27A97F3BC334EFULL,
   (u64bit) 0x76621220E66B17F4ULL, (u64bit) 0x967743899ACD7D0BULL, (u64bit) 0xF3EE5BCAE0ED6782ULL,
   (u64bit) 0x409F753600C879FCULL, (u64bit) 0x06D09A39B5926DB6ULL, (u64bit) 0x6F83AEB0317AC588ULL,
   (u64bit) 0x01E6CA4A86381F21ULL, (u64bit) 0x66FF3462D19F3025ULL, (u64bit) 0x72207C24DDFD3BFBULL,
   (u64bit) 0x4AF6B6D3E2ECE2EBULL, (u64bit) 0x9C994DBEC7EA08DEULL, (u64bit) 0x49ACE597B09A8BC4ULL,
   (u64bit) 0xB38C4766CF0797BAULL, (u64bit) 0x131B9373C57C2A75ULL, (u64bit) 0xB1822CCE61931E58ULL,
   (u64bit) 0x9D7555B909BA1C0CULL, (u64bit) 0x127FAFDD937D11D2ULL, (u64bit) 0x29DA3BADC66D92E4ULL,
   (u64bit) 0xA2C1D57154C2ECBCULL, (u64bit) 0x58C5134D82F6FE24ULL, (u64bit) 0x1C3AE3515B62274FULL,
   (u64bit) 0xE907C82E01CB8126ULL, (u64bit) 0xF8ED091913E37FCBULL, (u64bit) 0x3249D8F9C80046C9ULL,
   (u64bit) 0x80CF9BEDE388FB63ULL, (u64bit) 0x1881539A116CF19EULL, (u64bit) 0x5103F3F76BD52457ULL,
   (u64bit) 0x15B7E6F5AE47F7A8ULL, (u64bit) 0xDBD7C6DED47E9CCFULL, (u64bit) 0x44E55C410228BB1AULL,
   (u64bit) 0xB647D4255EDB4E99ULL, (u64bit) 0x5D11882BB8AAFC30ULL, (u64bit) 0xF5098BBB29D3212AULL,
   (u64bit) 0x8FB5EA14E90296B3ULL, (u64bit) 0x677B942157DD025AULL, (u64bit) 0xFB58E7C0A390ACB5ULL,
   (u64bit) 0x89D3674C83BD4A01ULL, (u64bit) 0x9E2DA4DF4BF3B93BULL, (u64bit) 0xFCC41E328CAB4829ULL,
   (u64bit) 0x03F38C96BA582C52ULL, (u64bit) 0xCAD1BDBD7FD85DB2ULL, (u64bit) 0xBBB442C16082AE83ULL,
   (u64bit) 0xB95FE86BA5DA9AB0ULL, (u64bit) 0xB22E04673771A93FULL, (u64bit) 0x845358C9493152D8ULL,
   (u64bit) 0xBE2A488697B4541EULL, (u64bit) 0x95A2DC2DD38E6966ULL, (u64bit) 0xC02C11AC923C852BULL,
   (u64bit) 0x2388B1990DF2A87BULL, (u64bit) 0x7C8008FA1B4F37BEULL, (u64bit) 0x1F70D0C84D54E503ULL,
   (u64bit) 0x5490ADEC7ECE57D4ULL, (u64bit) 0x002B3C27D9063A3AULL, (u64bit) 0x7EAEA3848030A2BFULL,
   (u64bit) 0xC602326DED2003C0ULL, (u64bit) 0x83A7287D69A94086ULL, (u64bit) 0xC57A5FCB30F57A8AULL,
   (u64bit) 0xB56844E479EBE779ULL, (u64bit) 0xA373B40F05DCBCE9ULL, (u64bit) 0xD71A786E88570EE2ULL,
   (u64bit) 0x879CBACDBDE8F6A0ULL, (u64bit) 0x976AD1BCC164A32FULL, (u64bit) 0xAB21E25E9666D78BULL,
   (u64bit) 0x901063AAE5E5C33CULL, (u64bit) 0x9818B34448698D90ULL, (u64bit) 0xE36487AE3E1E8ABBULL,
   (u64bit) 0xAFBDF931893BDCB4ULL, (u64bit) 0x6345A0DC5FBBD519ULL, (u64bit) 0x8628FE269B9465CAULL,
   (u64bit) 0x1E5D01603F9C51ECULL, (u64bit) 0x4DE44006A15049B7ULL, (u64bit) 0xBF6C70E5F776CBB1ULL,
   (u64bit) 0x411218F2EF552BEDULL, (u64bit) 0xCB0C0708705A36A3ULL, (u64bit) 0xE74D14754F986044ULL,
   (u64bit) 0xCD56D9430EA8280EULL, (u64bit) 0xC12591D7535F5065ULL, (u64bit) 0xC83223F1720AEF96ULL,
   (u64bit) 0xC3A0396F7363A51FULL };

}