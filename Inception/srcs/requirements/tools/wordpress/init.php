<?php
	error_reporting(0);
	
	$servername = $argv[1];
	$username = $argv[2];
	$password = $argv[3];
	$db_name = $argv[4];
	
	// Create connection
	while (1) {
		$conn = new mysqli($servername, $username, $password);
		// Check connection
		if (!$conn->connect_error) break;
		$conn->close();
		sleep(2);
	}
	
	// Create database
	$sql = "CREATE DATABASE IF NOT EXISTS ".$db_name." DEFAULT CHARACTER SET utf8";
	if ($conn->query($sql) === TRUE) {
	  echo "Database created successfully\n";
	} else {
	  echo "Error creating database: " . $conn->error."\n";
	}

	$conn->close();	
?>
