#include <pthread.h>
#include <unistd.h>

#include <glog/logging.h>
#include <uorb/abs_time.h>
#include <uorb/publication.h>
#include <uorb/publication_multi.h>
#include <uorb/subscription.h>
#include <uorb/subscription_interval.h>

#include <topics/example_string.h>


int main(int, char *[]) {
 	google::InitGoogleLogging("test");
	FLAGS_alsologtostderr = true;
	FLAGS_colorlogtostderr = true;
	google::SetLogDestination(google::GLOG_INFO, "./logs/INFO_");
	google::SetLogDestination(google::GLOG_WARNING, "./logs/WARNING_");
	google::SetLogDestination(google::GLOG_ERROR, "./logs/ERROR_");
	google::SetLogDestination(google::GLOG_FATAL, "./logs/FATAL_");

	LOG(INFO) << "UORB version: "<< orb_version() ;

	google::ShutdownGoogleLogging();
}
