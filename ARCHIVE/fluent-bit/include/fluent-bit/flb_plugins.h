/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2022 The Fluent Bit Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_PLUGINS_H
#define FLB_PLUGINS_H

#include <monkey/mk_core.h>
#include <fluent-bit/flb_custom.h>
#include <fluent-bit/flb_input.h>
#include <fluent-bit/flb_output.h>
#include <fluent-bit/flb_filter.h>
#include <fluent-bit/flb_config.h>
#include <fluent-bit/flb_log.h>

extern struct flb_custom_plugin custom_calyptia_plugin;
extern struct flb_input_plugin in_cpu_plugin;
extern struct flb_input_plugin in_mem_plugin;
extern struct flb_input_plugin in_thermal_plugin;
extern struct flb_input_plugin in_kmsg_plugin;
extern struct flb_input_plugin in_proc_plugin;
extern struct flb_input_plugin in_disk_plugin;
extern struct flb_input_plugin in_netif_plugin;
extern struct flb_input_plugin in_docker_plugin;
extern struct flb_input_plugin in_docker_events_plugin;
extern struct flb_input_plugin in_podman_metrics_plugin;
extern struct flb_input_plugin in_process_exporter_metrics_plugin;
extern struct flb_input_plugin in_node_exporter_metrics_plugin;
extern struct flb_input_plugin in_kubernetes_events_plugin;
extern struct flb_input_plugin in_kafka_plugin;
extern struct flb_input_plugin in_fluentbit_metrics_plugin;
extern struct flb_input_plugin in_prometheus_scrape_plugin;
extern struct flb_input_plugin in_emitter_plugin;
extern struct flb_input_plugin in_tail_plugin;
extern struct flb_input_plugin in_dummy_plugin;
extern struct flb_input_plugin in_head_plugin;
extern struct flb_input_plugin in_health_plugin;
extern struct flb_input_plugin in_http_plugin;
extern struct flb_input_plugin in_collectd_plugin;
extern struct flb_input_plugin in_statsd_plugin;
extern struct flb_input_plugin in_opentelemetry_plugin;
extern struct flb_input_plugin in_elasticsearch_plugin;
extern struct flb_input_plugin in_calyptia_fleet_plugin;
extern struct flb_input_plugin in_splunk_plugin;
extern struct flb_input_plugin in_event_test_plugin;
extern struct flb_input_plugin in_event_type_plugin;
extern struct flb_input_plugin in_storage_backlog_plugin;
extern struct flb_input_plugin in_nginx_exporter_metrics_plugin;
extern struct flb_input_plugin in_stream_processor_plugin;
extern struct flb_input_plugin in_serial_plugin;
extern struct flb_input_plugin in_stdin_plugin;
extern struct flb_input_plugin in_syslog_plugin;
extern struct flb_input_plugin in_exec_plugin;
extern struct flb_input_plugin in_udp_plugin;
extern struct flb_input_plugin in_exec_wasi_plugin;
extern struct flb_input_plugin in_tcp_plugin;
extern struct flb_input_plugin in_mqtt_plugin;
extern struct flb_input_plugin in_lib_plugin;
extern struct flb_input_plugin in_forward_plugin;
extern struct flb_input_plugin in_random_plugin;

extern struct flb_output_plugin out_azure_plugin;
extern struct flb_output_plugin out_azure_blob_plugin;
extern struct flb_output_plugin out_azure_logs_ingestion_plugin;
extern struct flb_output_plugin out_azure_kusto_plugin;
extern struct flb_output_plugin out_bigquery_plugin;
extern struct flb_output_plugin out_calyptia_plugin;
extern struct flb_output_plugin out_counter_plugin;
extern struct flb_output_plugin out_datadog_plugin;
extern struct flb_output_plugin out_es_plugin;
extern struct flb_output_plugin out_exit_plugin;
extern struct flb_output_plugin out_file_plugin;
extern struct flb_output_plugin out_forward_plugin;
extern struct flb_output_plugin out_http_plugin;
extern struct flb_output_plugin out_influxdb_plugin;
extern struct flb_output_plugin out_logdna_plugin;
extern struct flb_output_plugin out_loki_plugin;
extern struct flb_output_plugin out_kafka_plugin;
extern struct flb_output_plugin out_kafka_rest_plugin;
extern struct flb_output_plugin out_nats_plugin;
extern struct flb_output_plugin out_nrlogs_plugin;
extern struct flb_output_plugin out_null_plugin;
extern struct flb_output_plugin out_opensearch_plugin;
extern struct flb_output_plugin out_oracle_log_analytics_plugin;
extern struct flb_output_plugin out_plot_plugin;
extern struct flb_output_plugin out_skywalking_plugin;
extern struct flb_output_plugin out_slack_plugin;
extern struct flb_output_plugin out_splunk_plugin;
extern struct flb_output_plugin out_stackdriver_plugin;
extern struct flb_output_plugin out_stdout_plugin;
extern struct flb_output_plugin out_syslog_plugin;
extern struct flb_output_plugin out_tcp_plugin;
extern struct flb_output_plugin out_udp_plugin;
extern struct flb_output_plugin out_td_plugin;
extern struct flb_output_plugin out_lib_plugin;
extern struct flb_output_plugin out_flowcounter_plugin;
extern struct flb_output_plugin out_gelf_plugin;
extern struct flb_output_plugin out_websocket_plugin;
extern struct flb_output_plugin out_cloudwatch_logs_plugin;
extern struct flb_output_plugin out_kinesis_firehose_plugin;
extern struct flb_output_plugin out_kinesis_streams_plugin;
extern struct flb_output_plugin out_opentelemetry_plugin;
extern struct flb_output_plugin out_prometheus_exporter_plugin;
extern struct flb_output_plugin out_prometheus_remote_write_plugin;
extern struct flb_output_plugin out_s3_plugin;
extern struct flb_output_plugin out_vivo_exporter_plugin;
extern struct flb_output_plugin out_chronicle_plugin;

extern struct flb_filter_plugin filter_alter_size_plugin;
extern struct flb_filter_plugin filter_aws_plugin;
extern struct flb_filter_plugin filter_checklist_plugin;
extern struct flb_filter_plugin filter_ecs_plugin;
extern struct flb_filter_plugin filter_record_modifier_plugin;
extern struct flb_filter_plugin filter_sysinfo_plugin;
extern struct flb_filter_plugin filter_throttle_plugin;
extern struct flb_filter_plugin filter_type_converter_plugin;
extern struct flb_filter_plugin filter_kubernetes_plugin;
extern struct flb_filter_plugin filter_modify_plugin;
extern struct flb_filter_plugin filter_multiline_plugin;
extern struct flb_filter_plugin filter_nest_plugin;
extern struct flb_filter_plugin filter_parser_plugin;
extern struct flb_filter_plugin filter_expect_plugin;
extern struct flb_filter_plugin filter_grep_plugin;
extern struct flb_filter_plugin filter_rewrite_tag_plugin;
extern struct flb_filter_plugin filter_log_to_metrics_plugin;
extern struct flb_filter_plugin filter_lua_plugin;
extern struct flb_filter_plugin filter_stdout_plugin;
extern struct flb_filter_plugin filter_geoip2_plugin;
extern struct flb_filter_plugin filter_nightfall_plugin;
extern struct flb_filter_plugin filter_wasm_plugin;

extern struct flb_processor_plugin processor_labels_plugin;
extern struct flb_processor_plugin processor_attributes_plugin;


int flb_plugins_register(struct flb_config *config)
{
    struct flb_custom_plugin *custom;
    struct flb_input_plugin *in;
    struct flb_output_plugin *out;
    struct flb_filter_plugin *filter;
    struct flb_processor_plugin *processor;


    custom = flb_malloc(sizeof(struct flb_custom_plugin));
    if (!custom) {
        flb_errno();
        return -1;
    }
    memcpy(custom, &custom_calyptia_plugin, sizeof(struct flb_custom_plugin));
    mk_list_add(&custom->_head, &config->custom_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_cpu_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_mem_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_thermal_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_kmsg_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_proc_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_disk_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_netif_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_docker_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_docker_events_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_podman_metrics_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_process_exporter_metrics_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_node_exporter_metrics_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_kubernetes_events_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_kafka_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_fluentbit_metrics_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_prometheus_scrape_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_emitter_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_tail_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_dummy_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_head_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_health_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_http_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_collectd_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_statsd_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_opentelemetry_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_elasticsearch_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_calyptia_fleet_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_splunk_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_event_test_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_event_type_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_storage_backlog_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_nginx_exporter_metrics_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_stream_processor_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_serial_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_stdin_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_syslog_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_exec_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_udp_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_exec_wasi_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_tcp_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_mqtt_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_lib_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_forward_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);

    in = flb_malloc(sizeof(struct flb_input_plugin));
    if (!in) {
        flb_errno();
        return -1;
    }
    memcpy(in, &in_random_plugin, sizeof(struct flb_input_plugin));
    mk_list_add(&in->_head, &config->in_plugins);


    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_azure_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_azure_blob_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_azure_logs_ingestion_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_azure_kusto_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_bigquery_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_calyptia_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_counter_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_datadog_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_es_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_exit_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_file_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_forward_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_http_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_influxdb_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_logdna_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_loki_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_kafka_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_kafka_rest_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_nats_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_nrlogs_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_null_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_opensearch_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_oracle_log_analytics_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_plot_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_skywalking_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_slack_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_splunk_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_stackdriver_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_stdout_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_syslog_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_tcp_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_udp_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_td_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_lib_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_flowcounter_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_gelf_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_websocket_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_cloudwatch_logs_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_kinesis_firehose_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_kinesis_streams_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_opentelemetry_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_prometheus_exporter_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_prometheus_remote_write_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_s3_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_vivo_exporter_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);

    out = flb_malloc(sizeof(struct flb_output_plugin));
    if (!out) {
        flb_errno();
        return -1;
    }
    memcpy(out, &out_chronicle_plugin, sizeof(struct flb_output_plugin));
    mk_list_add(&out->_head, &config->out_plugins);


    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_alter_size_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_aws_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_checklist_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_ecs_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_record_modifier_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_sysinfo_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_throttle_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_type_converter_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_kubernetes_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_modify_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_multiline_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_nest_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_parser_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_expect_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_grep_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_rewrite_tag_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_log_to_metrics_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_lua_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_stdout_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_geoip2_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_nightfall_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);

    filter = flb_malloc(sizeof(struct flb_filter_plugin));
    if (!filter) {
        flb_errno();
        return -1;
    }
    memcpy(filter, &filter_wasm_plugin, sizeof(struct flb_filter_plugin));
    mk_list_add(&filter->_head, &config->filter_plugins);


    processor = flb_malloc(sizeof(struct flb_processor_plugin));
    if (!processor) {
        flb_errno();
        return -1;
    }
    memcpy(processor, &processor_labels_plugin, sizeof(struct flb_processor_plugin));
    mk_list_add(&processor->_head, &config->processor_plugins);

    processor = flb_malloc(sizeof(struct flb_processor_plugin));
    if (!processor) {
        flb_errno();
        return -1;
    }
    memcpy(processor, &processor_attributes_plugin, sizeof(struct flb_processor_plugin));
    mk_list_add(&processor->_head, &config->processor_plugins);



    return 0;
}

void flb_plugins_unregister(struct flb_config *config)
{
    struct mk_list *tmp;
    struct mk_list *head;
    struct flb_custom_plugin *custom;
    struct flb_input_plugin *in;
    struct flb_output_plugin *out;
    struct flb_filter_plugin *filter;
    struct flb_processor_plugin *processor;

    mk_list_foreach_safe(head, tmp, &config->custom_plugins) {
        custom = mk_list_entry(head, struct flb_custom_plugin, _head);
        mk_list_del(&custom->_head);
        flb_free(custom);
    }

    mk_list_foreach_safe(head, tmp, &config->in_plugins) {
        in = mk_list_entry(head, struct flb_input_plugin, _head);
        if(in->cb_destroy) {
            in->cb_destroy(in);
        }
        mk_list_del(&in->_head);
        flb_free(in);
    }

    mk_list_foreach_safe(head, tmp, &config->out_plugins) {
        out = mk_list_entry(head, struct flb_output_plugin, _head);
        if(out->cb_destroy) {
            out->cb_destroy(out);
        }
        mk_list_del(&out->_head);
        flb_free(out);
    }

    mk_list_foreach_safe(head, tmp, &config->filter_plugins) {
        filter = mk_list_entry(head, struct flb_filter_plugin, _head);
        mk_list_del(&filter->_head);
        flb_free(filter);
    }

    mk_list_foreach_safe(head, tmp, &config->processor_plugins) {
        processor = mk_list_entry(head, struct flb_processor_plugin, _head);
        mk_list_del(&processor->_head);
        flb_free(processor);
    }
}

#endif
