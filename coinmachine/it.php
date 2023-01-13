<?php
function resetDB($mysqli) {
	$muenze = [200, 100, 50, 20, 10, 5, 2, 1];
	$muenzeAmount = 200;

	$sql = "CREATE TABLE IF NOT EXISTS coins(VALUE INTEGER, AMOUNT INTEGER, PRIMARY KEY(VALUE))";

	$erg=$mysqli->query($sql);

	foreach($muenze as &$value) {
		$sql = "INSERT IGNORE INTO coins (VALUE, AMOUNT) VALUES ($value, $muenzeAmount)";
		$erg=$mysqli->query($sql);
	}
	foreach($muenze as &$value) {
        $sql = "UPDATE coins SET AMOUNT = $muenzeAmount WHERE coins.VALUE = $value";
		$erg=$mysqli->query($sql);
    }
}

$db_host="localhost:3306";
$db_name="it";
$db_user="root";
$db_password="root";

//$muenze = [200, 100, 50, 20, 10, 5, 2, 1];
$muenze = [];
$mysqli = new mysqli($db_host, $db_user, "",$db_name);

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
}

$sql="SELECT * FROM coins";
//Nummerierte ausgabe der Zufallszahlen
$erg=$mysqli->query($sql);
$i=$erg->num_rows-1;
while ($zeile=$erg->fetch_assoc()) {
    $muenze[$i--] = $zeile['VALUE'];
}

if(isset($_GET['generate'])) {
	$generate = filter_var($_GET['generate'], FILTER_VALIDATE_BOOLEAN);
} else {
	$generate = getopt("g", ["generate::"]);
}
if($generate) {
	echo "Resetting..." . PHP_EOL . "<br>";
	resetDB($mysqli);
}

if(isset($_GET['amount']) && isset($_GET['paid'])) {
    $amount = $_GET['amount'];
    $paid = $_GET['paid'];
    $rueckgeld = $paid - $amount;

    $cur = 0;
    $enoughMoney = true;

    while($rueckgeld > 0) {
        //Pruefe ob die Muenze zu gross ist
        if($rueckgeld>=$muenze[$cur]) {
                //Pruefe wie viele Cent uebrig bleiben
                $rest = $rueckgeld%$muenze[$cur];
                //Pruefe ob der Betrag veraendert wurde
                //Errechne wie oft die Muenze in unseren Betrag passt
                $n = ($rueckgeld-$rest)/$muenze[$cur];
                $sql="SELECT * FROM coins WHERE VALUE=$muenze[$cur]";
                $erg=$mysqli->query($sql);
                $row=$erg->fetch_assoc();
                $curAmount = $row["AMOUNT"];
                if($curAmount > $n) {
                    $rueckgeld = $rest;
                } else {
                    echo "Not enough $muenze[$cur]! Needing: $n <br>";
                }
        }
        $cur++;
        if($cur > 7 && $rueckgeld > 0) {
            echo "Money in machine not sufficient! Cannot perform the selling process. Sorry for inconvenience :-( <br>";
            $enoughMoney=false;
        }
    }

    if($enoughMoney) {
        $rueckgeld = $paid - $amount;

        $cur = 0;

        while($rueckgeld > 0) {
            //Pruefe ob die Muenze zu gross ist
            if($rueckgeld>=$muenze[$cur]) {
                    //Pruefe wie viele Cent uebrig bleiben
                    $rest = $rueckgeld%$muenze[$cur];
                    //Pruefe ob der Betrag veraendert wurde
                    //Errechne wie oft die Muenze in unseren Betrag passt
                    $n = ($rueckgeld-$rest)/$muenze[$cur];
                    $sql="SELECT * FROM coins WHERE VALUE=$muenze[$cur]";
                    $erg=$mysqli->query($sql);
                    $row=$erg->fetch_assoc();
                    $curAmount = $row["AMOUNT"];
                    if($curAmount > $n) {
                        $rueckgeld = $rest;
                        //Geld rauswerfen

                        printf("Gebe $n $muenze[$cur] ct Muenze(n) aus" . PHP_EOL . "<br>");

                        $sql = "UPDATE coins SET AMOUNT = ($curAmount-$n) WHERE coins.VALUE = $muenze[$cur]";
                        $erg=$mysqli->query($sql);
                    }
                    // else {
                    //     echo "Not enough $muenze[$cur]! Needing: $n <br>";
                    // }
            }
            $cur++;
        }
    }

}

    
echo "<svg id=\"statSvg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1021\" height=\"351\">\n";
$sql="SELECT * FROM coins";
$erg=$mysqli->query($sql);
$i=0;
$x=10;
$max=200;
while ($zeile=$erg->fetch_assoc()) {
	//echo $zeile['VALUE'] . ": " . $zeile['AMOUNT'] . "<br>" . PHP_EOL;
    $y=50+$i*(20+10);
    echo "<text x=\"" . $x . "\" y=\"" . $y . "\" font-size=\"12\" font-family=\"Arial\" fill=\"#404040\">" . $zeile['VALUE'] . " (" . $zeile['AMOUNT'] . ")" . "</text>\n";
    $y=35+$i*(20+10);
    $amount=$zeile['AMOUNT'];
    $percent=$amount/$max*100;
    if($percent > 10) {
        echo "<rect x=\"" . $x+60 . "\" y=\"" . $y . "\" width=\"" . ($amount * 4.5) . "\" height=\"20\" rx=\"3\" ry=\"3\" fill=\"#2A7BB4\" />\n";
    }
    else {
        echo "<rect x=\"" . $x+60 . "\" y=\"" . $y . "\" width=\"" . ($amount * 4.5) . "\" height=\"20\" rx=\"3\" ry=\"3\" fill=\"#FF0000\" />\n";
    }
    $i++;
}
$y=50+$i*(20+10);
echo "<line x1=\"71\" y1=\"10\" x2=\"71\" y2=\"" . $y . "\" stroke-width=\"2\" stroke=\"#808080\" />";
echo "</svg>\n";
?>
