<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1627487946971" ID="ID_1880155128" MODIFIED="1627491072726" TEXT="ManageYourBudgetMainMenu">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1880155128" ENDARROW="Default" ENDINCLINATION="-110;370;" ID="Arrow_ID_1417519456" SOURCE="ID_217944163" STARTARROW="None" STARTINCLINATION="-237;334;"/>
<node CREATED="1627488040731" ID="ID_1012432596" MODIFIED="1627488631728" POSITION="right" TEXT="userRegistration">
<node CREATED="1627488062810" ID="ID_1274017113" MODIFIED="1627488639035" TEXT="giveUserName"/>
<node CREATED="1627488073257" ID="ID_1431718746" MODIFIED="1627488644693" TEXT="giveUserSecondname"/>
<node CREATED="1627488083897" ID="ID_8364080" MODIFIED="1627489200649" TEXT="giveUserLogin">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_8364080" ENDARROW="Default" ENDINCLINATION="0;54;" ID="Arrow_ID_204472522" SOURCE="ID_1057053019" STARTARROW="None" STARTINCLINATION="2;78;"/>
<node CREATED="1627488297514" ID="ID_1970914790" MODIFIED="1627488654942" TEXT="isLoginExists">
<node CREATED="1627488330010" ID="ID_191238750" MODIFIED="1627488668561" TEXT="giveUserPassword">
<node CREATED="1627489288937" ID="ID_1356910747" MODIFIED="1627489296867" TEXT="userAccountCreated"/>
</node>
</node>
<node CREATED="1627488304665" ID="ID_821597474" MODIFIED="1627488660117" TEXT="!isLoginExists">
<node CREATED="1627488310570" ID="ID_1057053019" MODIFIED="1627489200649" TEXT="backToGiveLogin">
<arrowlink DESTINATION="ID_8364080" ENDARROW="Default" ENDINCLINATION="0;54;" ID="Arrow_ID_204472522" STARTARROW="None" STARTINCLINATION="2;78;"/>
</node>
</node>
</node>
</node>
<node CREATED="1627488136810" ID="ID_1701337609" MODIFIED="1627490819159" POSITION="right" TEXT="userLogin">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1701337609" ENDARROW="Default" ENDINCLINATION="-99;171;" ID="Arrow_ID_1702602541" SOURCE="ID_1294426736" STARTARROW="None" STARTINCLINATION="-76;113;"/>
<node CREATED="1627488145033" ID="ID_1621194441" MODIFIED="1627488883494" TEXT="passUserLogin">
<node CREATED="1627488153673" ID="ID_1357261954" MODIFIED="1627488614181" TEXT="isLoginExists">
<node CREATED="1627488202394" ID="ID_1523087596" MODIFIED="1627490994013" TEXT="giveUserPassword">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1523087596" ENDARROW="Default" ENDINCLINATION="-74;239;" ID="Arrow_ID_703679335" SOURCE="ID_1579643707" STARTARROW="None" STARTINCLINATION="-27;76;"/>
<node CREATED="1627490993904" ID="ID_806810653" MODIFIED="1627491002307" TEXT="isPasswordCorrect">
<node CREATED="1627488207978" ID="ID_1198860151" MODIFIED="1627491008537" TEXT="userLoggedIn">
<node CREATED="1627488221290" ID="ID_550220821" MODIFIED="1627491015007" TEXT="displayUserMenu">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_550220821" ENDARROW="Default" ENDINCLINATION="-232;277;" ID="Arrow_ID_1536555026" SOURCE="ID_1459065743" STARTARROW="None" STARTINCLINATION="39;44;"/>
<node CREATED="1627488524506" ID="ID_1068054530" MODIFIED="1627489558715" TEXT="addIncome">
<node CREATED="1627488790217" ID="ID_1811362814" MODIFIED="1627489005860" TEXT="selectOption">
<node CREATED="1627488926905" ID="ID_1319667439" MODIFIED="1627489083061" TEXT="incomeFromCurrentDay">
<node CREATED="1627488973178" ID="ID_267488902" MODIFIED="1627489552956" TEXT="getSystemDate">
<arrowlink DESTINATION="ID_304459864" ENDARROW="Default" ENDINCLINATION="-18;-58;" ID="Arrow_ID_1356078741" STARTARROW="None" STARTINCLINATION="99;-48;"/>
</node>
</node>
<node CREATED="1627488935081" ID="ID_1838457664" MODIFIED="1627488944954" TEXT="incomeFromAnotherDay">
<node CREATED="1627488984046" ID="ID_66380421" MODIFIED="1627489636216" TEXT="giveIncomeDate">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_66380421" ENDARROW="Default" ENDINCLINATION="32;26;" ID="Arrow_ID_1207848648" SOURCE="ID_1447322403" STARTARROW="None" STARTINCLINATION="33;17;"/>
<node CREATED="1627489014489" ID="ID_220474763" MODIFIED="1627489028858" TEXT="isDateCorrect">
<node CREATED="1627489028858" ID="ID_304459864" MODIFIED="1627489166259" TEXT="giveIncomeGroup">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_304459864" ENDARROW="Default" ENDINCLINATION="-18;-58;" ID="Arrow_ID_1356078741" SOURCE="ID_267488902" STARTARROW="None" STARTINCLINATION="99;-48;"/>
<node CREATED="1627489157834" ID="ID_237079397" MODIFIED="1627489177205" TEXT="incomeAmount">
<node CREATED="1627489350618" ID="ID_636246928" MODIFIED="1627489361042" TEXT="incomeAdded"/>
</node>
</node>
</node>
<node CREATED="1627489307465" ID="ID_528635903" MODIFIED="1627489330632" TEXT="!isDateCorrect">
<node CREATED="1627489319946" ID="ID_1447322403" MODIFIED="1627489636216" TEXT="backToGiveIncomeDate">
<arrowlink DESTINATION="ID_66380421" ENDARROW="Default" ENDINCLINATION="32;26;" ID="Arrow_ID_1207848648" STARTARROW="None" STARTINCLINATION="33;17;"/>
</node>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1627488683178" ID="ID_76498659" MODIFIED="1627488698090" TEXT="addExpense">
<node CREATED="1627489369402" ID="ID_335024977" MODIFIED="1627489374987" TEXT="selectOption">
<node CREATED="1627489374988" ID="ID_1764037108" MODIFIED="1627489382587" TEXT="expenseFromCurrentDay">
<node CREATED="1627489529565" ID="ID_1510009911" MODIFIED="1627489652289" TEXT="getSystemDate">
<arrowlink DESTINATION="ID_865072149" ENDARROW="Default" ENDINCLINATION="-30;-9;" ID="Arrow_ID_116770624" STARTARROW="None" STARTINCLINATION="10;29;"/>
</node>
</node>
<node CREATED="1627489383017" ID="ID_1371383261" MODIFIED="1627489485211" TEXT="expenseFromAnotherDay">
<node CREATED="1627489485213" ID="ID_1382657681" MODIFIED="1627489647450" TEXT="giveExpenseDate">
<node CREATED="1627489493296" ID="ID_1002653439" MODIFIED="1627489500268" TEXT="isDateCorrect">
<node CREATED="1627489500272" ID="ID_865072149" MODIFIED="1627489652289" TEXT="giveExpenseGroup">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_865072149" ENDARROW="Default" ENDINCLINATION="-30;-9;" ID="Arrow_ID_116770624" SOURCE="ID_1510009911" STARTARROW="None" STARTINCLINATION="10;29;"/>
<node CREATED="1627489509007" ID="ID_1640329600" MODIFIED="1627489516588" TEXT="expenseAmonut">
<node CREATED="1627489516590" ID="ID_73555951" MODIFIED="1627489521333" TEXT="expenseAdded"/>
</node>
</node>
</node>
<node CREATED="1627489562698" ID="ID_1333261797" MODIFIED="1627489570469" TEXT="!isDateCorrect">
<node CREATED="1627489571403" ID="ID_938928040" MODIFIED="1627489579911" TEXT="backToGiveExpenseDate"/>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1627490547609" ID="ID_904634149" MODIFIED="1627490557028" TEXT="currentMontBalanceSheet">
<node CREATED="1627488533897" ID="ID_956006390" MODIFIED="1627490571989" TEXT="getCurrentMonthFromSystemDate" VGAP="0">
<node CREATED="1627489675163" ID="ID_1140229763" MODIFIED="1627490761985" TEXT="getAllIncomesFromCurrentMonth">
<node CREATED="1627489702078" ID="ID_560599920" MODIFIED="1627489808118" TEXT="sortIncomesList(oldestOnTheTop)">
<node CREATED="1627489712861" ID="ID_783175752" MODIFIED="1627489868138" TEXT="displayIncomesList">
<node CREATED="1627489915529" ID="ID_596684661" MODIFIED="1627490024484" TEXT="displayIncomesAmount"/>
</node>
</node>
</node>
<node CREATED="1627489743721" ID="ID_1546670976" MODIFIED="1627490772263" TEXT="getAllExpensesFromCurrentMonth">
<node CREATED="1627489750717" ID="ID_1022236693" MODIFIED="1627489874384" TEXT="sortExpensesList(oldestOnTheTop)">
<node CREATED="1627489826893" ID="ID_1937805812" MODIFIED="1627489835210" TEXT="displayExpensesList">
<node CREATED="1627489925707" ID="ID_45259486" MODIFIED="1627490034582" TEXT="displayExpensesAmount"/>
</node>
</node>
</node>
<node CREATED="1627489883193" ID="ID_1430038912" MODIFIED="1627490485386" TEXT="displayDifferenceBetweenAmounts"/>
</node>
</node>
<node CREATED="1627488700281" ID="ID_1826571291" MODIFIED="1627488705925" TEXT="previousMonthBalanceSheet">
<node CREATED="1627490576923" ID="ID_871986469" MODIFIED="1627490646154" TEXT="getPreviousMonth(Current-1)">
<node CREATED="1627490646154" ID="ID_1368991317" MODIFIED="1627490744570" TEXT="getAllIncomesFromPreviosMonth">
<node CREATED="1627490656666" ID="ID_975540576" MODIFIED="1627490674631" TEXT="SortIncomesList(oldestOnTheTop)">
<node CREATED="1627490675499" ID="ID_1011121676" MODIFIED="1627490681450" TEXT="displayIncomesList">
<node CREATED="1627490681450" ID="ID_1420150501" MODIFIED="1627490687128" TEXT="displayIncomesAmount"/>
</node>
</node>
</node>
<node CREATED="1627490689690" ID="ID_800740949" MODIFIED="1627490702586" TEXT="getAllExpensesFromPreviousMonth">
<node CREATED="1627490702586" ID="ID_699719517" MODIFIED="1627490718874" TEXT="sortExpenses(oldestOnTheTop)">
<node CREATED="1627490718874" ID="ID_1668898244" MODIFIED="1627490726298" TEXT="displayExpensesList">
<node CREATED="1627490726298" ID="ID_394182160" MODIFIED="1627490731762" TEXT="displayExpensesAmount"/>
</node>
</node>
</node>
<node CREATED="1627490733994" ID="ID_833591357" MODIFIED="1627490741818" TEXT="displayDifferenceBetweenAmounts"/>
</node>
</node>
<node CREATED="1627488706505" ID="ID_1849443553" MODIFIED="1627488764963" TEXT="selectedPeriodBalanceSheet">
<node CREATED="1627490284730" ID="ID_1909228769" MODIFIED="1627490298826" TEXT="giveStartAndEndDateForBalanceSheet">
<node CREATED="1627490298826" ID="ID_1642673728" MODIFIED="1627490312571" TEXT="getAllIncomesFromSelectedPeriod">
<node CREATED="1627490312571" ID="ID_1823348908" MODIFIED="1627490327753" TEXT="sortIncomeList(oldestOnTheTop)">
<node CREATED="1627490327753" ID="ID_1812519006" MODIFIED="1627490337498" TEXT="displayIncomesList">
<node CREATED="1627490337498" ID="ID_471054234" MODIFIED="1627490348073" TEXT="displayIncomesAmount"/>
</node>
</node>
</node>
<node CREATED="1627490348873" ID="ID_1702902167" MODIFIED="1627490358011" TEXT="getAllExpensesFromSelectedPerod">
<node CREATED="1627490358011" ID="ID_153565109" MODIFIED="1627490368043" TEXT="sortExpenses(oldestOnTheTop)">
<node CREATED="1627490368043" ID="ID_1397354479" MODIFIED="1627490375546" TEXT="displayExpensesList">
<node CREATED="1627490375546" ID="ID_355060401" MODIFIED="1627490385113" TEXT="displayExpensesAmount"/>
</node>
</node>
</node>
<node CREATED="1627490385786" ID="ID_652359718" MODIFIED="1627490395010" TEXT="displayDifferenceBetweenAmounts"/>
</node>
</node>
<node CREATED="1627488771385" ID="ID_1404100729" MODIFIED="1627488777737" TEXT="passwordChange">
<node CREATED="1627490777484" ID="ID_1576061762" MODIFIED="1627490786091" TEXT="giveNewPassword">
<node CREATED="1627490786091" ID="ID_1421154394" MODIFIED="1627490898539" TEXT="passwordChange">
<node CREATED="1627490898539" ID="ID_1459065743" MODIFIED="1627490916828" TEXT="backToUserMenu">
<arrowlink DESTINATION="ID_550220821" ENDARROW="Default" ENDINCLINATION="-232;277;" ID="Arrow_ID_1536555026" STARTARROW="None" STARTINCLINATION="39;44;"/>
</node>
</node>
</node>
</node>
<node CREATED="1627488778201" ID="ID_1477978322" MODIFIED="1627488782964" TEXT="logout">
<node CREATED="1627490799561" ID="ID_217944163" MODIFIED="1627490851103" TEXT="backToMainMenu">
<arrowlink DESTINATION="ID_1880155128" ENDARROW="Default" ENDINCLINATION="-110;370;" ID="Arrow_ID_1417519456" STARTARROW="None" STARTINCLINATION="-237;334;"/>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1627488234425" HGAP="21" ID="ID_783693195" MODIFIED="1627488586506" TEXT="!isPasswordCorrect" VSHIFT="1">
<node CREATED="1627489229450" ID="ID_1579643707" MODIFIED="1627490821449" TEXT="backToGivePassword(3times)">
<arrowlink DESTINATION="ID_1523087596" ENDARROW="Default" ENDINCLINATION="-74;239;" ID="Arrow_ID_703679335" STARTARROW="None" STARTINCLINATION="-27;76;"/>
</node>
</node>
</node>
</node>
<node CREATED="1627488171113" ID="ID_846407065" MODIFIED="1627488619740" TEXT="!isLoginExists">
<node CREATED="1627488184730" ID="ID_1294426736" MODIFIED="1627490819159" TEXT="backToMainMenu">
<arrowlink DESTINATION="ID_1701337609" ENDARROW="Default" ENDINCLINATION="-99;171;" ID="Arrow_ID_1702602541" STARTARROW="None" STARTINCLINATION="-76;113;"/>
</node>
</node>
</node>
</node>
</node>
</map>
