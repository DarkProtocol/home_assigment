<?php 

function dd($var)
{
	echo '<pre>';
	print_r($var);
	echo '</pre>';

}


//Сортировка вставками
function insertSort($array, $number) {
    $count = count($array);

    if ($count <= 1) {
        return $array;
    }
 
    for ($i = 1; $i < $count; $i++) {

        $current = $array[$i];
        $x = $i - 1;
 
        while ( isset($array[$x]) && ($array[$x][$number] > $current[$number]) ) {
            $array[$x + 1] = $array[$x];
            $array[$x] = $current;
            $x--;
        }
    }
 
    return $array;
}

//Быстрая сортировка
function quickSort($array, $number) {

    $count = count($array);

    if ($count <= 1) {
        return $array;
    }
 
    $first = $array[0];
    $leftArray = [];
    $rightArray = [];
 
    for ($i = 1; $i < $count; $i++) {

        if ($array[$i][$number] <= $first[$number]) {

            $leftArray[] = $array[$i];

        } else {

            $rightArray[] = $array[$i];

        }
    }
 
    $leftArray = quickSort($leftArray, $number);
    $rightArray = quickSort($rightArray, $number);
 
    return array_merge($leftArray, array($first), $rightArray);
}


$startPeriod = mktime(0, 0, 0, 1, 1, 1980);
$endPeriod = mktime(0, 0, 0, 12, 31, 1984);

$file = fopen("laba.csv", "r");

$period = [];
$data = [];



while ( ($csv = fgetcsv($file, 1000, ",")) !== FALSE ) {

	if ( $csv[1] >= $startPeriod && $csv[1] <= $endPeriod )
		$period[] = $csv;

    $data[] = $csv;

}

fclose($file);

// отсортируем в quickSort
$quickSortTime = microtime(true);

$quickSortArray = quickSort($period, 0);
echo 'Результат быстрой сортировки: '. $quickSortArray[0][0] . '</br>';


$quickSortTime = microtime(true) - $quickSortTime;

// отсортируем в insetSort

$insertSortTime = microtime(true);

$insertSortArray = insertSort($period, 0);
echo  'Результат сортировки вставками: '. $insertSortArray[0][0] . '</br></br>';

$insertSortTime = microtime(true) - $insertSortTime;

echo "Время быстрой сортировки: $quickSortTime ms </br> Время сортировки вставками: $insertSortTime ms </br></br>";

if ( $quickSortTime > $insertSortTime ) 
	echo "Время сортировки вставками меньше";

elseif ( $quickSortTime < $insertSortTime )
	echo  'Время быстрой сортировки меньше';

else 
	echo 'Время одинаково';




