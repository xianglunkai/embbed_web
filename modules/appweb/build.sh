

read -p "Please select build platform:[arm7.5 arm4.8 x64]" platform
case $platform in
        arm7.5)
        echo " build platform on arm7.5"
        make -f projects/appweb-linux-T3.mk
        ;;
        arm4.8)
        echo " build platform on arm4.8"

        ;;
        x64)
        echo " build platform on x64"
    	make -f projects/appweb-linux-default.mk
        ;;
esac
