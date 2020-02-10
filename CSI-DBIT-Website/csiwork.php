<!DOCTYPE html>
<html>
<title>CSI Work</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="styles.css">
<link rel="stylesheet" href="tableOfProject.css">
<link rel="icon" href="dbit.png" type="image/png">
<style>
body, h1, h2, h3, h4, h5 {
	font-family: "Courier New", sans-serif
}

body {
	font-size: 100%;
}

table {
	font-family: "Courier New", sans-serif;
	border-collapse: collapse;
	width: 100%;
}

td, th {
	border: 1px solid #000000;
	text-align: left;
	padding: 8px;
}

th {
	text-align: center;
}

tr:nth-child(even) {
	background-color: #dddddd;
}
</style>
<body>
	<!-- Sidebar/menu -->
	<nav class="w3-sidebar w3-teal w3-collapse w3-top w3-large w3-padding"
		style="z-index: 3; width: 300px; font-weight: bold;" id="mySidebar">
		<br> <a href="javascript:void(0)" onclick="w3_close()"
			class="w3-button w3-hide-large w3-display-topleft"
			style="width: 100%; font-size: 22px">Close Menu</a>
		<div class="w3-container">
			<h3 class="w3-padding-64">
				<b>CSI-DBIT<br>Student Chapter
				</b>
			</h3>
		</div>
		<div class="w3-bar-block">
			<a href="index.php" onclick="w3_close()"
				class="w3-bar-item w3-button w3-hover-white">Home</a> <a
				href="about.html" onclick="w3_close()"
				class="w3-bar-item w3-button w3-hover-white">About CSI</a> <a
				href="#csiwork" onclick="w3_close()"
				class="w3-bar-item w3-button w3-hover-white">CSI Work</a> <a
				href="committee.html" onclick="w3_close()"
				class="w3-bar-item w3-button w3-hover-white">CSI Core Committee
				2017</a> <a href="contact.html" onclick="w3_close()"
				class="w3-bar-item w3-button w3-hover-white">Contact Us</a>
		</div>
		</div>
	</nav>

	<!-- Top menu on small screens -->
	<header
		class="w3-container w3-top w3-hide-large w3-teal w3-xlarge w3-padding">
		<a href="javascript:void(0)" class="w3-button w3-teal w3-margin-right"
			onclick="w3_open()">☰</a> <span>CSI-DBIT</span>
	</header>

	<!-- Overlay effect when opening sidebar on small screens -->
	<div class="w3-overlay w3-hide-large" onclick="w3_close()"
		style="cursor: pointer" title="close side menu" id="myOverlay"></div>

	<!-- !PAGE CONTENT! -->
	<div class="w3-main" style="margin-left: 340px; margin-right: 40px">

		<!-- CSI Work-->
		<div class="w3-container" id="csiwork" style="margin-top: 80px">
			<h1 class="w3-xxlarge w3-text-teal">< csi_work /></h1>
			<hr style="width: 50px; border: 5px solid teal" class="w3-round">
		</div>

		<!-- Table of Work -->
		<table>
			<tr>
				<th>Workshop Name</th>
				<th>Conducted by</th>
				<th>Footfall</th>
				<th>Report</th>
			</tr>
			<?php
   include "database.php";
   
   $sql = 'select * from csiwork';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) 
   {
  	echo "<tr>";
  	echo "<td>" . $row['name'] . "</td>";
  	echo "<td>" . $row['conduct'] . "</td>";
  	echo "<td>" . $row['footfall'] . "</td>";
  	echo "<td><a href='/csi/pdf/".$row['doc']."'>" . $row['doc'] . "</a></td>";
  	echo "</tr>";
   }
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
		</table>
		<!-- Work End Here  -->

		<!-- End page content -->
	</div>
	<br>
	<!-- W3.CSS Container -->
	<div class="w3-light-grey w3-container w3-padding-32"
		style="padding-right: 58px">
		<p class="w3-right">Developed by CSI DBIT</p>
	</div>

	<script>
		// Script to open and close sidebar
		function w3_open() {
			document.getElementById("mySidebar").style.display = "block";
			document.getElementById("myOverlay").style.display = "block";
		}

		function w3_close() {
			document.getElementById("mySidebar").style.display = "none";
			document.getElementById("myOverlay").style.display = "none";
		}
	</script>

</body>
</html>
