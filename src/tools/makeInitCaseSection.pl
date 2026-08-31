#!/usr/bin/perl
#-------------------------------------------------------------------------------------------------------------------------------
#
# Filename: makeInitCaseSection.pl
#
# Authour: Silvano Catinella <catinella@yahoo.com>
#
# Language: Perl-5
#
# Description
#	This script populates the main case-switch in the wError_init(), automatically. The required submodules data are
#	acknowledged by tags placed inside of every submodule's header file.
#	Tags:
#		WERROR_SUBCLASS_ID
#`		WERROR_SUBCLASS_INITPROC
#
#-------------------------------------------------------------------------------------------------------------------------------
my @hFiles = glob( $dir . 'wErrorWith*.h' );
my $id = "";

if (scalar(@ARGV) != 1) {
	printf("ERROR! use %s {debug|<filename>}\n");
	exit(127);

} else {
	my $target = $ARGV[0]; 
	my $row;
	my $tfh;
	my $sfh;
	
	if ($target ne "debug") {
		open($tfh, ">", $target) or die "ERROR! I cannot open the \"$target\" file\n";
	}

	foreach (@hFiles) {
		open($sfh, "< $_") or die "ERROR! I cannot open the \"$_\" file\n";
		print("$_ file reading...\n");
		while ($row = <$sfh>) {
			chomp;
			if ($row =~ /^[\t ]*\/\/[ \t]*WERROR_SUBCLASS_ID::[ \t]*(.+)/) {
				$id = $1;

			} elsif ($row =~ /^[\t ]*\/\/[ \t]*WERROR_SUBCLASS_INITPROC::[ \t]*(.+)/) {
				$iproc = $1;
			}
		}
		close($sfh);

		if ($target ne "debug") {
			print($tfh "\n\n");
			print($tfh "\tcase $id:\n");
			print($tfh "\t\t$iproc(obj);\n");
			print($tfh "\tbreak;\n");
		} else {
			print("\n\n");
			print("\tcase $id:\n");
			print("\t\t$iproc(obj);\n");
			print("\tbreak;\n");
		}
	}
 }
if ($target ne "debug") {
	close($tfh);
}

exit(0);
