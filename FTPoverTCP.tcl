set ns [new Simulator]

$ns color 1 red

set namfile1 [open TCPout.nam w]
$ns namtrace-all $namfile1

proc finish {} {
	global ns namfile1
	$ns flush-trace
	close $namfile1
	exec nam TCPout.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]


$ns duplex-link $n0 $n1 5Mb 10ms DropTail
$ns duplex-link $n1 $n2 1.5Mb 10ms DropTail
$ns duplex-link $n2 $n3 5Mb 10ms DropTail

$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient right-up


 
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP


$ns at 0.1 "$ftp start"
$ns at 4.5 "$ftp stop"

$ns at 5 "finish"

$ns run
