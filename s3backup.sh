#!/bin/bash
	bdate=$(date +%Y%m%d)
	btime=$(date +%H%M)
	dirname=(echo $dir |rev|cut -d/ -f1|rev)
	tar zcvf ~/$bdate-$btime-$dirname-backup.tar.gz $dir
	aws s3 cp ~/$bdate-$btime-$dirname-backup.tar.gz s3://Link/website/