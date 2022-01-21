#!/bin/sh

if [ $# -ne 3 ]; then
	echo "Syntax: vrfsetup.sh bin-directory resources-directory destination-directory"
	exit 1
fi

binDirectory="$1"
resourcesDirectory="$2"
outputDirectory="$3"

function vrfsetup_generate_link() {
	${binDirectory}/catapult.tools.linker -r ${resourcesDirectory} -s $1 --linkedPublicKey $2 --output ${outputDirectory}/$3
}

vrfsetup_generate_link '934B1829665F7324362380E844CBEDA2C103AAEFD3A2C4645DC1715AC29E52E6' '6979A295EEE7DFD28BDB8CF8FE4E69B9ABF8DF1F48E64ABA38C64904404FA43C' 0001.dat
vrfsetup_generate_link '83133E126ED380826B41B395FE64E3C989E9EE801FF198EDE46BF2E64A37DA79' 'F3293999A083C9DDACE82FB74E2C53AD399D80A3C6190F3E27DC1247C2C64CB9' 0002.dat
vrfsetup_generate_link '6ED36237A9ED61F6BB8A06C85A4C9A07AA15625A2876804073F680DB823CF83B' '7E851742FAEAF7CA6986077AC4DDE78E225649C5AF7F4FC6A63778B4767BB042' 0003.dat
vrfsetup_generate_link 'B28691530189655A0CFE65025A91D22E68985B1015228DB8259ABAE33C0BFBD7' '9C5261B1FF9312027454C17F8C73179D84B6133F7AC4C8427C3BCE5988A614A8' 0004.dat
vrfsetup_generate_link '98F08FBFA850C174EDDABE745FFD4180D20C07B4F91A6E73B39C7E1DC7CEA070' '5675B71AC631975643309562D3C0DB8FA8B39C5EBFAA30EEA175CCBFCEA467FC' 0005.dat
vrfsetup_generate_link 'F0E9FACD9BAF4B593D16D1E07130B4F430583E2F503367D556980624ED5E2AA1' '135F3C38E2E5CECAF045B8121A2ECC5A6AA859D00B53BAE9E8B8D0D4D82C7C1B' 0006.dat
vrfsetup_generate_link '952C995AA82294C0C675AA24053716EB2B8058EC4A71C52F024376E8C947681A' 'E7E29932C0CE240480565161C447627177E76AC4BFE8DCFBBCBF2BACBB66881E' 0007.dat
vrfsetup_generate_link '4385BBE4CE2F6101BDBB8660B2F1ABBC577D9E73F1DE4B47FD63659126B2AA98' '5BF050D642E64888C87B3B3BCBA0EABAD6E677F5B3413ECF2D58580F6D843A4B' 0008.dat
vrfsetup_generate_link 'FACA8FB0278A7B13DBCF855C52442716CA6F734B152F97CBE0CE4EC216547B5C' '981A88DEB091FA7F27BD320D89996A21E6922F308273BBCA7DCB9216FB403364' 0009.dat
vrfsetup_generate_link '33CBFFC1CE4D671E2DE435ECE770B9B3637F18FB9E87BB6310E101952FDFA7CD' 'B4BE952D81679F93F67493B4935CCD6B9A0EC36F22EFB08155BB7A1D0416E06C' 000a.dat
vrfsetup_generate_link 'C521E74AC0B33A34F8A4743FB67700CB2D78F5D25E0C05687DF025E630793864' '8499BA45D53117B39BAED431A44E5D97FB77F88A5DF22D9E46278F477ED8BDD8' 000b.dat
