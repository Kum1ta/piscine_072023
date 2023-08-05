# Piscine juillet 2023 Angoulême

<strong>❗❗ Ces fichiers ne sont pas là pour être utilisé pendant une piscine. Je vous conseille très vivement de ne pas copier les codes ni même de les regarder. Un tuteur ou un staff pourrait vous pénaliser.❗❗ </strong>

<h1>Résultat de la moulinette avec des infos complémentaires : </h1>

<h2>BSQ :</h2>

![bsq](https://github.com/Kum1ta/piscine_072023/assets/59119791/114a7f5c-f754-427d-a42f-6f24b9c22024)
Le bsq était reussi mais 2 petits problémes : 
_ Une petite erreur en cas de problème de malloc dans fill_buffer. Il manque un * dans la condition.
_ On a oublié de remettre une fonction qui verifie qu'il n'y a que les caractères présents dans la première ligne dans toute la map.

<h2>C00 :</h2>

![c00](https://github.com/Kum1ta/piscine_072023/assets/59119791/f1a8586e-6950-471e-bc97-36b9a72d230f)

<h2>C01 :</h2>

![c01](https://github.com/Kum1ta/piscine_072023/assets/59119791/84649895-0d77-4b7a-a7a3-638e5f62f885)

<h2>C02 :</h2>

![c02](https://github.com/Kum1ta/piscine_072023/assets/59119791/5ee41bc7-f796-43d5-b1a0-d9de40babaa4)
Des petites erreurs assez bête pour le dernier exo mais il est largement faisable.

<h2>C03 :</h2>

![c03](https://github.com/Kum1ta/piscine_072023/assets/59119791/9ec4eb11-f57b-446d-a62f-dfb7ad2314e9)

<h2>C04 :</h2>

![c04](https://github.com/Kum1ta/piscine_072023/assets/59119791/5b9c3bb5-c715-47ff-ae31-0b123ac8de64)

<h2>C05 :</h2>

![c05](https://github.com/Kum1ta/piscine_072023/assets/59119791/fcba2065-02f5-42c3-bb05-7822c5fbeb13)

<h2>C06 :</h2>

![c06](https://github.com/Kum1ta/piscine_072023/assets/59119791/4f8082f2-c095-4b15-bbfb-36b4a11d4f46)

<h2>C07 :</h2>

![c07](https://github.com/Kum1ta/piscine_072023/assets/59119791/b0b54fcb-8e91-407b-9b98-11c363d266e1)

<h2>C08 :</h2>

![c08](https://github.com/Kum1ta/piscine_072023/assets/59119791/417d9aa5-1071-4d9f-b4b6-2df49c39d491)

<h2>C09 :</h2>

![c09](https://github.com/Kum1ta/piscine_072023/assets/59119791/ffa2a5cc-7d03-4606-9cad-9f38990aac8f)

<h2>C10 :</h2>

![c10](https://github.com/Kum1ta/piscine_072023/assets/59119791/521b61f6-2ee0-4864-b97c-377a8ceb85f0)
Plusieurs trucs à dire par rapport à ce C10. Notre piscine avait repéré un bug dans la moulinette pour ft_tail qui faisait des tests sans le -c alors que c'est explicitement dit que tous les tests sont fait avec. Donc vérifiez bien votre trace pour en être sûr. Autre truc, ne vous forcez pas à utiliser chaque fonction autorisée. Par exemple, basename n'est pas utile avant ft_hexdump. 

<h2>C11 :</h2>

![c11](https://github.com/Kum1ta/piscine_072023/assets/59119791/e40f167c-745a-4526-a792-cbe1d457e82e)

<h2>Rush00 :</h2>

![rush00](https://github.com/Kum1ta/piscine_072023/assets/59119791/46584d47-10c5-41c9-84d6-3c5ce12c66cf)
Le problème est extrêmement simple. Le code est parfait mais on a oublié de gérer les cas où on a un chiffre inférieur ou égal à 0.

<h2>Rush01 :</h2>

![rush01](https://github.com/Kum1ta/piscine_072023/assets/59119791/45493f9e-0649-4f1e-96de-9ec59d0f3151)
Le code fonctionne très bien mais problème d'optimisation. La fonction define_locate() est ultra lente donc il suffit de la remplacer pour des calculs et ça sera bien plus efficace. Tel quel, le programme fait les maps de 1x1 à 6x6.

<h2>Shell00 :</h2>

![s00](https://github.com/Kum1ta/piscine_072023/assets/59119791/85bafe3c-5a7d-4df1-8801-c4375fff3efd)

<h2>Shell01 :</h2>

![s01](https://github.com/Kum1ta/piscine_072023/assets/59119791/bcf945b3-b2d0-4bd7-bb07-2f01448b113e)
Pour les shells, je vous conseille de ne pas perdre de temps dessus et de passer au c00 dès le premier mercredi de votre piscine.

<h2>Exam00 :</h2>

<table style="text-align:center;">
  <tr><td><strong>Exercice</strong></td><td><strong>Resultat</strong></td></tr>
  <tr><td>only_a</td><td>0/100</td></tr>
  <tr><td>aff_a</td><td>10/100</td></tr>
  <tr><td>maff_alpha</td><td>20/100</td></tr>
  <tr><td>ft_dec</td><td>30/100</td></tr>
  <tr><td>write_string</td><td>40/100</td></tr>
  <tr><td>print_interval</td><td>50/100</td></tr>
  <tr><td>occ_z</td><td>60/100</td></tr>
  <tr><td>ft_strrev</td><td>70/100</td></tr>
  <tr><td>ft_strcmp</td><td>80/100</td></tr>
  <tr><td>ft_atoi</td><td>90/100</td></tr>
  <tr><td>Résultat final : 100/100 (1h10)</td></tr>
<table>

<h2>Exam01 :</h2>

<table style="text-align:center;">
  <tr><td><strong>Exercice</strong></td><td><strong>Resultat</strong></td></tr>
  <tr><td>ft_start</td><td>0/100</td></tr>
  <tr><td>ft_swap</td><td>10/100</td></tr>
  <tr><td>ft_putstr</td><td>20/100</td></tr>
  <tr><td>ft_strlen</td><td>30/100</td></tr>
  <tr><td>fizzbuzz</td><td>40/100</td></tr>
  <tr><td>ft_strcpy</td><td>50/100</td></tr>
  <tr><td>ft_atoi</td><td>60/100</td></tr>
  <tr><td>aff_last_param</td><td>70/100</td></tr>
  <tr><td>search_and_remplace</td><td>80/100</td></tr>
  <tr><td>count_word</td><td>90/100</td></tr>
  <tr><td>Résultat final : 100/100 (1h10)</td></tr>
<table>

<h2>Exam02 :</h2>

<table style="text-align:center;">
  <tr><td><strong>Exercice</strong></td><td><strong>Resultat</strong></td></tr>
  <tr><td>hello</td><td>0/100</td></tr>
  <tr><td>write_string</td><td>10/100</td></tr>
  <tr><td>first_word</td><td>20/100</td></tr>
  <tr><td>ft_strlen</td><td>30/100</td></tr>
  <tr><td>ft_putnbr</td><td>40/100</td></tr>
  <tr><td>aff_last_param</td><td>50/100</td></tr>
  <tr><td>last_word</td><td>60/100</td></tr>
  <tr><td>count_word</td><td>70/100</td></tr>
  <tr><td>ft_itoa</td><td>80/100</td></tr>
  <tr><td>ft_split</td><td>90/100</td></tr>
  <tr><td>Résultat final : 100/100 (1h17)</td></tr>
<table>

<h2>Exam03 (final) :</h2>

<table style="text-align:center;">
  <tr><td><strong>Exercice</strong></td><td><strong>Resultat</strong></td></tr>
  <tr><td>aff_b</td><td>0/100</td></tr>
  <tr><td>maff_revalpha</td><td>6/100</td></tr>
  <tr><td>ft_strcmp</td><td>12/100</td></tr>
  <tr><td>count_len</td><td>18/100</td></tr>
  <tr><td>ft_atoi</td><td>24/100</td></tr>
  <tr><td>print_even</td><td>30/100</td></tr>
  <tr><td>ft_putnbr</td><td>36/100</td></tr>
  <tr><td>aff_last_param</td><td>42/100</td></tr>
  <tr><td>is_palindrome</td><td>48/100</td></tr>
  <tr><td>count_word</td><td>54/100</td></tr>
  <tr><td>ft_itoa</td><td>60/100</td></tr>
  <tr><td>ft_split</td><td>66/100</td></tr>
  <tr><td>ft_list_remove_if</td><td>72/100</td></tr>
  <tr><td>count_alpha</td><td>78/100</td></tr>
  <tr><td>str_maxlenoc</td><td>84/100</td></tr>
  <tr><td>infini_mult</td><td>90/100</td></tr>
  <tr><td>Résultat final : 90/100 (6h17)</td></tr>
<table>


