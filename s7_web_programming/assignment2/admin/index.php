<?php
session_start();

$host = 'database';
$port = 3000;
$db = 'bloodbank';
$user = 'admin';
$pass = 'password';

$conn = new mysqli($host, $user, $pass, $db, $port);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$isLoggedIn = isset($_SESSION['email']);
$userType = $isLoggedIn ? $_SESSION['user_type'] : null;

if ($isLoggedIn) {
    if ($userType === 'admin') {
        if (basename($_SERVER['SCRIPT_NAME']) === 'index.php') {
            header('Location: donations.php');
            exit();
        }
    }
}
?>
